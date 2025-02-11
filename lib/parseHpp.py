# ver 1.3
# //-define-file body MyLib.cpp 
# //-define-file header MyLib.h
# //-only-file body
# #include <iostream>
# #include "MyLib.h"
# 
# //-only-file body //-
# //- {NEXT[0:]}
# //-only-file header ;
# void say_hello()
# //-only-file body
# {
#     std::cout << "Hello, from MyLib!\n";    
# }

import os
import re
import sys
import concurrent.futures

class FileClass:
    file_path = ""
    file_id = ""
    file_content = []

import os

def update_file_if_needed(file_path, new_content):
    """
    Checks if the content of the file at file_path is different from new_content.
    If different, deletes the file and writes new_content to it.
    If the same, does nothing.
    """
    # Check if the file exists
    if os.path.exists(file_path):
        with open(file_path, 'r') as file:
            content = file.read()

        if content != new_content:
            print("File content changed: " + file_path)
            # Delete the file
            os.remove(file_path)
            
            # Write new_content to the file
            with open(file_path, 'w') as file:
                file.write(new_content)
    else:
        # If the file doesn't exist, create it and write new_content
        with open(file_path, 'w') as file:
            file.write(new_content)



def remove_default_assignment(declaration):
    # Regular expression to match default assignments
    pattern = re.compile(r'\s*=\s*".*?"|\s*=\s*\w+|\s*=\s*\(.*?\)\s*=>\s*\{.*?\}')
    # Replace the default assignments with an empty string
    result = re.sub(pattern, '', declaration)
    result = re.sub(r" override(\s|\n)", "", result)
    result = re.sub(r" explicit(\s|\n)", "", result)
    result = re.sub(r" virtual(\s|\n)", "", result) 
    
    return result

def replace_next(template, NEXT):
    def replacer(match):
        expr = match.group(1)
        if ':' in expr:
            parts = expr.split(':')
            start = int(parts[0]) if parts[0] else 0
            end = int(parts[1]) if parts[1] else len(NEXT)
            return ' '.join(NEXT[start:end])
        else:
            index = int(expr)
            return NEXT[index]
    
    pattern = re.compile(r'\{NEXT\[(.*?)\]\}')
    result = pattern.sub(replacer, template)
    return result


import re

import re

def get_string_parts(line, with_quotes=False):
    if with_quotes:
        pattern = re.compile(r'(\".*?\"|\S+<.*?>|\S+\s*\*\s*|\S+)')
    else:
        pattern = re.compile(r'\"(.*?)\"|(\S+<.*?>|\S+\s*\*\s*|\S+)')
    
    matches = pattern.findall(line)
    
    if with_quotes:
        parts = [match for match in matches]
    else:
        parts = [match[0] or match[1] for match in matches]
    
    return parts



def extract_next_value(string):
    """
    Extracts the integer value following "{NEXT:" in the given string.

    Args:
        string: The input string to be checked.

    Returns:
        The integer value if found, otherwise None.
    """
    match = re.search(r'{NEXT([^}]+)}', string)
    if match:
        return match.group(1)
    else:
        return None


is_defining_template = False
templates_map = {}
current_template = ""
def parse_file(input_file):
    global is_defining_template
    global templates_map
    global current_template
    with open(input_file, 'r') as file:
        lines = file.readlines()

    fileMap = {"null": FileClass()}
    varsMap = {}

    is_only_file = False
    only_file_id = ""
    remove_remark = False
    append_semicolon = False

    is_next_text = False
    next_text = ""
    next_text_skip_only_files = 1
    next_only_file_id = ""

    lines_without_templates = []   
    line_number = 1
    for line in lines:
        line_number = line_number + 1
        lstrip_line = line.lstrip()
        if lstrip_line.startswith("//-template"):
            parts = get_string_parts(lstrip_line)
            is_defining_template = True
            current_template = parts[1]
            templates_map[current_template] = ""            
        elif is_defining_template:
            if lstrip_line.startswith("//-end-template"):
                is_defining_template = False
                current_template = ""
            else:
                templates_map[current_template] += line  
        else:
            if lstrip_line.startswith("//- {function}") or lstrip_line.startswith("//- {fn}") :
                lines_without_templates.append("//-only-file header \n")            
                text = f"#line {line_number} " + '"' + input_file +  '"' + "\n"
                lines_without_templates.append(text)            
            lines_without_templates.append(line)
            if lstrip_line.startswith("//-only-file body"):
                text = f"#line {line_number} " + '"' + input_file +  '"' + "\n"
                lines_without_templates.append(text)



    lines = []
    for t in templates_map:
        for i in range(len(lines_without_templates)):
            lstrip_line = lines_without_templates[i].lstrip()
            parts = get_string_parts(lstrip_line)
            if len(parts) >= 2 and parts[0] == "//-" and parts[1] == t:    
                str_template = templates_map[t]
                i=0
                for itm in parts[2:]:
                    str_template = str_template.replace("{PRM_" + str(i) + "}", itm)
                    i+=1

                splited = str_template.splitlines()
                splited = [line + "\n" for line in splited]
                lines.extend(splited)
            else:
                lines.append(lines_without_templates[i])
        lines_without_templates = lines

    if not templates_map:
        lines = lines_without_templates


    for line in lines:        
        lstrip_line = line.lstrip()
        if lstrip_line.startswith("//-define-file"):            
            parts = get_string_parts(lstrip_line)
            
            fileMap[parts[1]] = FileClass()
            fileMap[parts[1]].file_id = parts[1]
            fileMap[parts[1]].file_path = parts[2]
            fileMap[parts[1]].file_content = []  
        elif lstrip_line.startswith("//-var"):
            parts = get_string_parts(lstrip_line)
            varsMap[parts[1]] = parts[2]            
        elif lstrip_line.startswith("//-only-file"):
            if is_next_text:
                if next_text_skip_only_files > 0:
                    next_text_skip_only_files -= 1
                else:  
                    for i in range(len(fileMap[next_only_file_id].file_content)):
                        template = fileMap[next_only_file_id].file_content[i]
                        NEXT = get_string_parts(next_text, True)

                        if extract_next_value(template) is not None:                            
                            fileMap[next_only_file_id].file_content[i]  = replace_next(template, NEXT)
                            fileMap[next_only_file_id].file_content[i] = remove_default_assignment(fileMap[next_only_file_id].file_content[i])                            
                            

                    is_next_text = False
                    next_text = ""
                    next_text_skip_only_files = 1                    
            if append_semicolon:
                append_semicolon = False
                fileMap[only_file_id].file_content[-1] = fileMap[only_file_id].file_content[-1].rstrip() + ";\n"
            parts = get_string_parts(lstrip_line)
            is_only_file = True
            only_file_id = parts[1]
            remove_remark = False
            if len(parts) > 2:
                remove_remark = parts[2] == "//-"  
                append_semicolon = parts[2] == ";"         
    
        elif is_only_file:
            if remove_remark:
                line = line.replace("//- ", "")
                next_value = extract_next_value(line)
                if next_value is not None:
                    is_next_text = True
                    next_text = ""
                    next_text_skip_only_files = 1
                    next_only_file_id = only_file_id               
                for var in varsMap:
                    line = line.replace(var, varsMap[var])
            elif is_next_text:
                next_text += line
            fileMap[only_file_id].file_content.append(line)

    for file_id in fileMap:        
        if fileMap[file_id].file_content and file_id != "null":            
            print("Write file " + fileMap[file_id].file_path)
            update_file_if_needed(fileMap[file_id].file_path, "".join(fileMap[file_id].file_content))
            #with open(fileMap[file_id].file_path, 'w') as file:
            #    file.writelines(fileMap[file_id].file_content)





if __name__ == "__main__":
    with concurrent.futures.ThreadPoolExecutor(max_workers=5) as executor:
        futures = []
        # Templates should be read none async
        parse_file(sys.argv[1])
        for arg in sys.argv[2:]:
            futures.append( executor.submit(parse_file, arg) )

        for future in concurrent.futures.as_completed(futures):
            future.result()

