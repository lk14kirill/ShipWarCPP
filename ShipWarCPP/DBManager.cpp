#include "DBManager.h"
#include "PlayerProfile.h"
#include <pqxx/pqxx>
using namespace std;

void DBManager::AddProfileToDB(PlayerProfile profile)
{
    try
    {
        string sqlAdd = format("Insert into {0} \nvalues ('{1}',{2},{3},'{4}','{5}')",
            tableName,
            profile.GetName(),
            profile.GetWins(),
            (int)profile.GetType(),
            profile.GetLogin(),
            profile.GetPassword());
            
        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work worker(connectionObject);
        pqxx::result response = worker.exec0(sqlAdd);
        worker.commit();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        cin;
    }
}
PlayerProfile DBManager::GetProfile(string login, string password)
{
    try
    {
        string sqlAdd = format("SELECT * from {0} where login = '{1}' and pswrd = '{2}' ",tableName, login, password);

        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work worker(connectionObject);
        pqxx::row response = worker.exec1(sqlAdd);

        return PlayerProfile(response[0].as<string>(), response[1].as<int>(), PlayerType(response[2].as<int>()), login, password);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        cin;
    }
}
bool DBManager::IsProfileValid(string login, string password)
{
    try
    {
        string sqlAdd = format("SELECT * from {0} where login = '{1}' and pswrd = '{2}' ", tableName, login, password);

        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work worker(connectionObject);
        pqxx::row response = worker.exec1(sqlAdd);

        return true;
    }
    catch (const std::exception& e)
    {
        //std::cerr << e.what() << std::endl;
        return false;
    }
}
bool DBManager::IsLoginUsed(string login)
{
    try
    {
        string sqlAdd = format("SELECT * from {0} where login = '{1}' ", tableName, login);

        pqxx::connection connectionObject(connectionString.c_str());
        pqxx::work worker(connectionObject);
        pqxx::row response = worker.exec1(sqlAdd);

        return true;
    }
    catch (const std::exception& e)
    {
        //std::cerr << e.what() << std::endl;
        std::cout << "Login is free." << endl;
        return false;
    }
}
