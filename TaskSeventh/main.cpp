#include <iostream>
#include <vector>

using namespace std;


using FlightTable = vector<pair<string, vector<string>>>;


bool canTravel(const FlightTable& flights, const string& start, const string& destination) {
    
    if (start == destination)
        return true;

   
    vector<string> visited_cities;
   
    visited_cities.push_back(start);

    
    for (const auto& flight : flights) {
       
        if (flight.first == start) {
            
            for (const string& next_city : flight.second) {
            
                if (find(visited_cities.begin(), visited_cities.end(), next_city) == visited_cities.end()) {
                   
                    if (next_city == destination)
                        return true;
                 
                    visited_cities.push_back(next_city);
                }
            }
        }
    }

    
    return false;
}

int main() {

    FlightTable flights = {
        {"Kyiv", {"Lviv", "Kharkiv", "Dnipro", "Odesa"}},
        {"Lviv", {"Kyiv", "Kharkiv", "Ternopil", "Uzhhorod"}},
        {"Kharkiv", {"Kyiv", "Lviv", "Dnipro", "Sumy"}},
        {"Dnipro", {"Kyiv", "Kharkiv", "Zaporizhzhia", "Poltava"}},
        {"Odesa", {"Kyiv", "Zaporizhzhia", "Mykolaiv", "Kherson"}},
        {"Ternopil", {"Lviv", "Rivne", "Ivano-Frankivsk", "Zhytomyr"}},
        {"Uzhhorod", {"Lviv", "Mukachevo", "Chop", "Ivano-Frankivsk"}},
        {"Lutsk", {"Rivne", "Zhytomyr", "Chernivtsi", "Ivano-Frankivsk"}},
        {"Rivne", {"Lutsk", "Ternopil", "Zhytomyr", "Ivano-Frankivsk"}},
        {"Ivano-Frankivsk", {"Ternopil", "Lutsk", "Chernivtsi", "Lviv"}},
        {"Zhytomyr", {"Ternopil", "Lutsk", "Rivne", "Kyiv"}},
        {"Sumy", {"Kharkiv", "Poltava", "Cherkasy", "Kropyvnytskyi"}},
        {"Donetsk", {"Zaporizhzhia", "Mariupol", "Luhansk", "Sloviansk"}},
        {"Luhansk", {"Donetsk", "Zaporizhzhia", "Mariupol", "Khartsyzk"}},
        {"Zaporizhzhia", {"Dnipro", "Donetsk", "Melitopol", "Odesa"}},
        {"Simferopol", {"Kherson", "Dnipro", "Krasnoperekopsk", "Yevpatoriia"}},
        {"Chernivtsi", {"Ternopil", "Lutsk", "Ivano-Frankivsk", "Khmelnytskyi"}},
        {"Khmelnytskyi", {"Vinnytsia", "Chernivtsi", "Zhytomyr", "Rivne"}},
        {"Vinnytsia", {"Khmelnytskyi", "Zhytomyr", "Kyiv", "Zhmerinka"}},
        {"Cherkasy", {"Sumy", "Poltava", "Kropyvnytskyi", "Kyiv"}},
        {"Poltava", {"Sumy", "Dnipro", "Cherkasy", "Kropyvnytskyi"}},
        {"Chernihiv", {"Sumy", "Kyiv", "Nizhyn", "Pryluky"}},
        {"Kropyvnytskyi", {"Poltava", "Cherkasy", "Mykolaiv", "Dnipro"}},
        {"Mykolaiv", {"Odesa", "Kropyvnytskyi", "Zaporizhzhia", "Kherson"}},
        {"Kherson", {"Mykolaiv", "Odesa", "Simferopol", "Zaporizhzhia"}}
    };

   
    string start_city, destination_city;
    cout << "Enter the starting city: ";
    cin >> start_city;
    cout << "Enter the destination city: ";
    cin >> destination_city;

    
    if (canTravel(flights, start_city, destination_city))
        cout << "It's possible to travel from " << start_city << " to " << destination_city << endl;
    else
        cout << "It's not possible to travel from " << start_city << " to " << destination_city << endl;
    system("pause");
    return 0;
}
