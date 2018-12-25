#!/usr/bin/awk -f

function output_string(name, value)
{
    if ((name == "") || (value == "") || (value ~ /end/)) {
        return;
    }
    
    printf(" %s=\"%s\"", name, value);
}

function output_percent(name, value, divisor)
{
    if ((name == "") || (value == "") || (divisor == 0)) {
        return;
    }

    printf(" %s=\"%.2f%%\"", name, value * 100 / divisor);
}

function output_indent(indent_level)
{
	if (indent_level < 0) {
		return;
	}
		
	# output_indent_space
	for (i = 1; i < indent_level; i++) {
		printf("  ");
	}
}

function xml_enter_level(level)
{
	level++;
	return level;
}

function xml_leave_level(level)
{
	if (level > 0) {
		level--;
	}
	return level;
}


BEGIN {
    output_buffer[1] = "name";
    output_buffer[2] = "x";
    output_buffer[3] = "y";
    output_buffer[4] = "w";
    output_buffer[5] = "h";
	indent_level = 0;
	
    if (ARGC < 4) {
        printf("Usage: makexml.sh filename screen_length screen_width\n");
        exit;
    }

    while (getline < ARGV[1] > 0) {
		if ($0 ~ /^$/) { # remove the empty line
            continue;
        }
        if (($NF == "end") && (NF == 2) ) {
			output_indent(indent_level);
            printf("</%s>\n", $1);
			indent_level = xml_leave_level(indent_level);
            continue;
        } 

        if ($1 ~ /window/) {
            printf("<window");
            output_string(output_buffer[2], $3);
            output_string(output_buffer[3], $4);
            output_string("style", $5);
            printf(">\n");
			indent_level = xml_enter_level(indent_level);
		    continue;  # 处理 window 事件
        }
		
		indent_level = xml_enter_level(indent_level);
			
		output_indent(indent_level);
		printf("<%s", $1);
	
        for (i = 2; i < 5; i++) {
            output_string(output_buffer[i - 1], $i);
        }
		
		output_percent("w", $5, ARGV[2]);
        output_percent("h", $6, ARGV[3]);
          
        count = NF - 6;
            
        switch ($1) {
        case /label/: {
            if (count) {
                output_string("text", $7);
				output_string("style", $8)
            }
            break;
        }
        case /image/: {
            if (count) {
                output_string("image", $7);
                output_string("style", $8);
                output_string("draw_type", $9);
            }
            break;
        }
        case /button/: {
            if (count) {
                output_string("style", $7);
            }
            break;
        }
            
        default: break;
        } 
		
		if ($NF == "end") {
			printf("/>\n");
			indent_level = xml_leave_level(indent_level);
		} else {
			printf(">\n");
		}
    }
                               
    exit; 
}

END {
  
}



