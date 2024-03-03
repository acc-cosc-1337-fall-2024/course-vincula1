//add include statements

#include <string>

//add function code here

double get_gc_content(const std::string& dna) {
    int count = 0;
    for(char c : dna) {
        if(c == 'C' || c == 'G') count++;
    }
    return static_cast<double>(count) / dna.length();
}

std::string get_reverse_string(std::string dna) {
    std::string reversed;
    for(int i = dna.length() - 1; i >= 0; i--) {
        reversed += dna[i];
    }
    return reversed;
}

std::string get_dna_compliment(std::string dna) {
    dna = get_reverse_string(dna);
    for(char &c : dna) {
        switch(c) {
            case 'A': c = 'T'; break;
            case 'T': c = 'A'; break;
            case 'C': c = 'G'; break;
            case 'G': c = 'C'; break;
        }
    }
    return dna;
}