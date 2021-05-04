#pragma once

class cypher {
    private:
        char* buffer; //This stores the value to be decoded/encoded
        size_t length; //This keeps track of the buffer's length.
        uint8_t encoder; //This determines the encryption.
        mutable bool isDecoded; //Makes sure we don't encode/decode twice.
   
public:
      
        cypher(const char* buffer) {
            
            this->length = strlen(buffer) + 1;

            //Allocating the buffer array.
            this->buffer = new char[this->length];

            /*Copying contents of the argument to the buffer of the
            current instance of the class. while onsidering null termination.
            */
            memcpy(this->buffer, buffer, this->length); 

            //Setting the default encoder value.
            this->encoder = 32;

            this->isDecoded=true;
        }

        //Overloading the '=' operator to make the class more practical.
        void operator=(const char* buffer) {
            this->length = strlen(buffer) + 1;
            this->buffer = new char[this->length];
            memcpy(this->buffer, buffer, this->length);
        }
            
        size_t Length() {
            return this->length;
        }
    
        void SetEncoder(const uint8_t& encoder) {
         /*
            This function sets the encoder value.
            The encoder determines the cyphering,
            you can experiment with this funtion to
            see the different values you'll get.
        */
            this->encoder = encoder;
        }

        void encode() const{
            /*
                This funtion does the encodding with respect
                to the encoder's value.
                Note: Be sure to use the same encoder value when you decode.
            */
            if (this->isDecoded == true) {
                for (uint8_t i = 0; i < this->length; i++) {
                    this->buffer[i] = (uint32_t)this->buffer[i] + this->encoder;
                }
                this->isDecoded = false;
            }
        }

        const char* c_str() {
            //This function returns the buffer as a const char *
            return this->buffer;
        }

        void decode() const{
            /*
            This function decodes the buffer with respect to the encoder.
            Note: You will get incorrect results if you decode
            with a value which is different from the value you encoded with. 
            */
            if (this->isDecoded == false){
                for (uint8_t i = 0; i < this->length; i++) {
                    this->buffer[i] = (uint32_t)this->buffer[i] - this->encoder;
                }
                this->isDecoded = true;
            }
        }

            //Overloading the << operator to make the class more practical to use.
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

            //Deletes the copy constructor to prevent shallow copying of cypher objects.
        cypher(const cypher&) = delete;

        ~cypher() {
            delete this->buffer;
        }
};
