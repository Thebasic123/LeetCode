//simple function for calculating postfix expression

// Input: ["4", "13", "5", "/", "+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6

namespace Eval{
    std::vector<std::string> operators{"*","/","+","-"};
    std::unordered_map<std::string,int> operators_map;

    void initializeMap(){
        for(const auto& op : operators){
            if(operators_map.count(op)==0){
                operators_map[op] = 1;
            }
        }
    }
    void addOpeartor(const std::string& newOp){
        operators.push_back(newOp);
        if(operators_map.count(newOp)==0){
            operators_map[newOp] = 1;
        }
    }
    std::vector<std::string> tokenizeString(const std::string& inputStr,const std::string& delimiter=" "){
        std::vector<std::string> result;
        if(inputStr.length()==0){
            return result;
        }
        size_t pos = 0;
        std::string token;
        std::string s = inputStr;
        while((pos = s.find(delimiter))!= std::string::npos){
            token = s.substr(0,pos);
            result.push_back(token);
            s.erase(0,pos+delimiter.length());
        }
        return result;
    }    
    template 





    int evalRPN(const std::vector<std::string>& tokens) {
        std::stack<int> s;
        int result = 0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i][0]=='*'||tokens[i][0]=='/'||tokens[i][0]=='+'||tokens[i][0]=='-'){
                //check if negative sign represents negative number in this case
                if(tokens[i][0]=='-'&&tokens[i].length()>1){
                    s.push(std::stoi(tokens[i]));
                    continue;
                }
                //check whether stack has >= 2 elements left
                if(s.size()<2){
                    if(tokens[i].length()==1){
                        std::cout<<"invalid expression!!"<<std::endl;
                        return 0;   
                    }
                }
                int first = 0;
                int second = 0;
                second = s.top();
                s.pop();
                first = s.top();
                s.pop();   
                int tempVal = 0;
                if(tokens[i][0]=='*'){
                    tempVal = first * second;
                }else if(tokens[i][0]=='/'){
                    tempVal = first / second;
                }else if(tokens[i][0]=='-'){
                    tempVal = first - second;
                }else if(tokens[i][0]=='+'){
                    tempVal = first + second;
                }
                s.push(tempVal);
            }else{
                s.push(std::stoi(tokens[i]));
            }
        }
        result = s.top();
        return result;
    }
};
