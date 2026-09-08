#pragma once

#include <Arduino.h>
#include "../include/Configuration.h"

#define MAX_CMD_SIZE 96

class GCodeParser {
private:
    char line_buffer[MAX_CMD_SIZE];
    uint8_t buffer_index = 0;

public:
    void init() {
        Serial.begin(BAUDRATE);
        buffer_index = 0;
    }

    void poll() {
        while (Serial.available() > 0) {
            char c = Serial.read();
            if (c == '\n' || c == '\r') {
                if (buffer_index > 0) {
                    line_buffer[buffer_index] = '\0';
                    parse_command(line_buffer);
                    buffer_index = 0;
                }
            } else {
                if (buffer_index < (MAX_CMD_SIZE - 1)) {
                    line_buffer[buffer_index++] = c;
                }
            }
        }
    }

private:
    void parse_command(char* cmd) {
        if (cmd[0] == 'G' || cmd[0] == 'g') {
            int code = atoi(&cmd[1]);
            if (code == 0 || code == 1) {
                float target_x = get_axis_value('X', cmd);
                float target_y = get_axis_value('Y', cmd);
                float target_z = get_axis_value('Z', cmd);
                float target_e = get_axis_value('E', cmd);
                
               
                (void)target_x;
                (void)target_y;
                (void)target_z;
                (void)target_e;
            }
        } else if (cmd[0] == 'M' || cmd[0] == 'm') {
            int code = atoi(&cmd[1]);
            if (code == 104) {
                float temp = get_axis_value('S', cmd);
                (void)temp; 
            } else if (code == 140) {
                float temp = get_axis_value('S', cmd);
                (void)temp; 
            }
        }
        Serial.println("ok");
    }

    float get_axis_value(char axis, const char* cmd) {
        const char* p = strchr(cmd, axis);
        if (!p) {
            p = strchr(cmd, axis + 32); 
        }
        if (p) {
            return atof(p + 1);
        }
        return 0.0f;
    }
};
