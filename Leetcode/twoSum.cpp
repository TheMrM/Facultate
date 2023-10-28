class Solution {
public:
    vector<int> twoSum(vector<int>& nums; int target) {
        //Creem o notatie pentru a tine evidenta numerelor
        unorder_map<int, int> _map;

        for(int i = 0; i < nums.size(); i++) {
            //Luam un numar din lista data
            int num = nums[i];
            //Cautam numarul complementar necesar
            int complement = target - num;

            //Cautam numarul complementar in notita
            auto it = _map.find(complement);

            //Daca gasim un numar complementar in notita
            if (it != _map.end()) {
                //Intoarcem pozitiile celor doua numere care formeaza perechea
                return {it->second, i};
            }

            //Daca nu gasim un numar complementar, notam numarul si pozitia sa in notitia
            _map[num] = i;
        }

        //Daca am parcurs toate numerele si nu am gasit o pereche, intoarcem o lista goala
        return {};
    }
};