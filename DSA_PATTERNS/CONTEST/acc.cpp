string encryption(string s) {

    string modified = "";

    for(auto ch : s) {
        if(ch != " "){
            modified += ch;
        }
    }

    int L = modified.length();

    int row = floor(sqrt(L));
    int col = ceil((sqrt(L))/row)
}