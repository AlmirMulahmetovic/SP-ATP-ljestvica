#ifndef PLAYER_H
#define PLAYER_H

class player
{
    public:
        player();
        string Get_first_name() { return _first_name; }
        void Set_first_name(string val) { _first_name = val; }
        string Get_last_name() { return _last_name; }
        void Set_last_name(string val) { _last_name = val; }
        string Get_nationality() { return _nationality; }
        void Set_nationality(string val) { _nationality = val; }
        int Get_points() { return _points; }
        void Set_points(int val) { _points = val; }
        void Set_player(string first_name,string last_name,int points);
        friend ostream& operator<<(ostream& out,const player& val )
        {
            out<<val._last_name<<","<<val._first_name<<"("<<val._nationality<<") Points: "<<val._points;

        }
        friend istream& operator<<(istream& in,const player& val )
        {
            cout<<"Insert Player\n";
            cout<<"First name:";
            in>>val._first_name;
            cout<<"Last name:";
            in>>val._last_name
            cout<<"Nationality:";
            in>>val._nationality;
            cout<<"Points:"
            in>>val._points;
        }
    protected:
    private:
        string _first_name;
        string _last_name;
        string _nationality;
        int _points;
};

#endif // PLAYER_H
