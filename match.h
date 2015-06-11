#ifndef MATCH_H
#define MATCH_H


class Match
{
    public:
        Match();
        player Get_name_of_first_player() { return _name_of_first_player; }
        void Set_name_of_first_player(player val) { _name_of_first_player = val; }
        player Get_name_of_second_player() { return _name_of_second_player; }
        void Set_name_of_second_player(player val) { _name_of_second_player = val; }
        string Get_result() { return _result; }
        void Set_result(string val) { _result = val; }
        void Set_Match(player name_first,player name_second,string result);

        friend ostream& operator<<(ostream& out,const Match& val )
        {
            out<<val._name_of_first_player<<" - "<<val._name_of_second_player<<"Result: "<<val._result;

        }
        /*
        friend istream& operator<<(istream& in,player& val )
        {

             in>>val._name_of_first_player;
             in>>val._name_of_second_player;
             in>>val._result;
        }
        */
    protected:
    private:
        player _name_of_first_player;
        player _name_of_second_player;
        string _result;
};

#endif // MATCH_H
