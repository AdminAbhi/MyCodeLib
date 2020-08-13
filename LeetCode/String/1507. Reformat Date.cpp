class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> month = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
                                                {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        string dd = date[1] < 95? date.substr(0,2): "0" + date.substr(0,1);
        string mm = date[1] < 95? month[date.substr(5,3)]: month[date.substr(4,3)];
        string yy = date[1] < 95? date.substr(9): date.substr(8);
        return yy + '-' + mm + '-' + dd;
    }
};
