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

class FileClass:
    file_path = ""
    file_id = ""
    file_content = []

def replace_next(template, NEXT):
    def replacer(match):
        expr = match.group(1)
        if ':' in expr:
            start = int(expr.split(':')[0])
            return ' '.join(NEXT[start:])
        else:
            index = int(expr)
            return NEXT[index]
    
    pattern = re.compile(r'\{NEXT\[(.*?)\]\}')
    result = pattern.sub(replacer, template)
    return result


def get_string_parts(line):
    pattern = re.compile(r'\"(.*?)\"|(\S+)')
    matches = pattern.findall(line)
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

    fileMap = {}
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
    for line in lines:
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
            lines_without_templates.append(line)

    lines = []
    for t in templates_map:
        for i in range(len(lines_without_templates)):
            lstrip_line = lines_without_templates[i].lstrip()
            if lstrip_line.startswith("//- " + t):         
                splited = templates_map[t].splitlines()
                splited = [line + "\n" for line in splited]
                lines.extend(splited)
            else:
                lines.append(lines_without_templates[i])
        lines_without_templates = lines


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
                        NEXT = get_string_parts(next_text)

                        if extract_next_value(template) is not None:
                            fileMap[next_only_file_id].file_content[i]  = replace_next(template, NEXT)
                            

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
        print("Writing file " + fileMap[file_id].file_path)
        if fileMap[file_id].file_content:            
            with open(fileMap[file_id].file_path, 'w') as file:
                file.writelines(fileMap[file_id].file_content)

if __name__ == "__main__":
    for arg in sys.argv[1:]:
        parse_file(arg)    