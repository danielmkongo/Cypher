#pragma once

#include<iostream>
#if 0
Real programmers don't comment
#endif


class cypher {
    private:
    
        char* buffer;
        size_t length;
        uint8_t encoder;
        bool isDecoded;
   
public:
        cypher(const char* buffer) {
            this->length = strlen(buffer) + 1;
            this->buffer = new char[this->length];
            memcpy(this->buffer, buffer, this->length); 
            this->encoder = 32;
            this->isDecoded=true;
        }

        void operator=(const const char* buffer) {
            this->length = strlen(buffer) + 1;
            this->buffer = new char[this->length];
            memcpy(this->buffer, buffer, this->length);
        }

        void SetEncoder(const uint8_t& encoder) {
            this->encoder = encoder;
        }

        void encode() {
            if (this->isDecoded == true) {
                for (uint8_t i = 0; i < this->length; i++) {
                    this->buffer[i] = (uint32_t)this->buffer[i] + this->encoder;
                }
                this->isDecoded = false;
            }
        }

        void decode() {
            if (this->isDecoded == false){
                for (uint8_t i = 0; i < this->length; i++) {
                    this->buffer[i] = (uint32_t)this->buffer[i] - this->encoder;
                }
                this->isDecoded = true;
            }
        }

        friend std::ostream& operator<<(std::ostream& stream, const cypher& object) {
            stream << object.buffer;
            return stream;
        }

        cypher() {
            this->buffer = nullptr;
            this->encoder = 32;
            this->isDecoded = true;
            this->length = 0;
        }

        cypher(const cypher&) = delete;

        ~cypher() {
            delete this->buffer;
        }
};
