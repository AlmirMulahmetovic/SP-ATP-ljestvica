#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include<iostream>

class player
{
    public:
        player();
        player(const player& Player);
        const std::string& Get_first_name() const;
        void Set_first_name(std::string val);
        const std::string& Get_last_name() const;
        void Set_last_name(std::string val);
        const std::string& Get_nationality() const;
        void Set_nationality(std::string val);
        const int& Get_points() const;
        void Set_points(int val);
        void Set_player(std::string first_name,std::string last_name,std::string nationality ,int points);

        friend std::ostream& operator<<(std::ostream& out,const player& val )
        {
            out<<val._last_name<<","<<val._first_name<<"("<<val._nationality<<") Points: "<<val._points;
            return out;

        }
        friend std::istream& operator<<(std::istream& in,player& val )
        {
            std::cout<<"Insert Player\n";
            std::cout<<"First name:";
            in>>val._first_name;
            std::cout<<"Last name:";
            in>>val._last_name;
            std::cout<<"Nationality:";
            in>>val._nationality;
            std::cout<<"Points:";
            in>>val._points;
            return in;
        }


        bool operator==(const player& Player) const;
        bool operator!=(const player& Player) const;
        bool operator<(const player& Player) const;
        bool operator>(const player& Player) const;
        bool operator<=(const player& Player) const;
        bool operator>=(const player& Player) const;

    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nationality;
        int _points;
};
//dodao ALMIR
#endif // PLAYER_H
