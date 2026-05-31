// cland.c
//
//      我的建議是用 save() & restore() 的方法, 將所有幫派的資料
//      存在 query_save_file() 那
//
//                                                      Created by Arthur
//
//      如要防止巫師竄改資料, 可以在要防止的地方加上, 若限定只有 ROOT_UID 可以改
//      if( previous_object() && geteuid(previous_object()) != ROOT_UID )
//              return;
// 1999 05/09 為了新的系統重新改寫                      By  Chan

#include <clan.h>

inherit F_SAVE;

int check_last_num(string,string,string);

mapping clans;
                        // 目前是暫定這些東西, 可以自行對照, 如有加新的,
                        // 也請加在下面, 這樣比較好理解
                        // clans["幫派的 id"] = ([
                        //      "gold"          : 錢,
                        //      "members"       : ({ 幫眾 id 的 array }),
                        //      "master"        : 幫主的 id,
                        //      "name"          : 幫派名稱,
                        //      "level2"        : ({ array }),
                        //      "level3"        : ({ array }),
                        //      "level4"        : ({ array }),
                        //      "home"          : 幫派的家,
                        //      "develop"       : 幫派人材發展狀況,
                        //      "weapon"        : 幫派武器發展狀況,
                        //      "war"           : 幫派戰爭狀態,
                        //      "tax"           : 稅率
                        //      "alert"         : 警戒、備戰狀態
                        //      "ally"          : 同盟,
                        //      ]);

string *LEVEL   = ({ "level2", "level3", "level4" });

mapping query_clans()   { return clans; }
string query_save_file() { return DATA_DIR + "clan"; }

// 用來加減 clan 的錢
int add_money(string clan_id, int num)
{

       if( !mapp(clans[clan_id]) )
                return notify_fail("沒有這個幫派。\n");
        clans[clan_id]["gold"] += num;
        return num;
}

// 用來加減某值 by Chan
int add_clanset(string clan_id,string what,int num)
{
        if( !mapp(clans[clan_id]) )
                return notify_fail("沒有這個幫派。\n");
        clans[clan_id][what] += num;
        return num;
}

// 創新的 clan, master 是幫主 id,
int create_clan(string master, string clan_id, string clanname)
{

        int i;
        string npc_path,clannumber,clanename;
        if( mapp(clans) && mapp(clans[clan_id]))
                return 0;
        clans[clan_id] = ([
                "master"        : master,
                "name"          : clanname,
                "level2"        : ({}),
                "level3"        : ({}),
                "level4"        : ({}),
                "home"          : CLAN_HOME+clan_id+"/room/hall.c",
                "gold"          : 1000000,
                "members"       : ({ master }),
                "develop"       : 0,
                "weapon"        : 0,
                "armor_tech"    : 0,
                "board"         : 1,
                "prestige"      : 10000,
                "weapon_fund"   : 0,
                "armor_fund"    : 0,
                "war"           : 0,
                "tax"           : 5,
        ]);
        // 送他一間房間當開幫紀念
        assure_file( clans[clan_id]["home"] );
        CLAN_CMDS("c_room_make")->create_room(clans[clan_id]["home"]);
//建立npc的目錄
        save();
        npc_path=CLAN_HOME+clan_id+"/npc";
        mkdir(npc_path);
        npc_path=CLAN_HOME+clan_id+"/weapon";
        mkdir(npc_path);
        npc_path=CLAN_HOME+clan_id+"/armor";
        mkdir(npc_path);
        npc_path=CLAN_HOME+clan_id+"/item";
        mkdir(npc_path);
        npc_path="/log/clan/"+clan_id;
        mkdir(npc_path);

        return 1;
}

void create()
{
        seteuid(getuid());
        restore();
        // 設定每個 level 的人數上限, 在這邊設定才可以更改
        if( !mapp(clans) )
                clans = ([]);
        clans["limit"] = ([
                "level2" : LEVEL2_NUM,
                "level3" : LEVEL3_NUM,
                "level4" : LEVEL4_NUM,
        ]);
}

// 幫派位階升降, 逐出幫眾, return 0 表示額滿或沒該位階
int clan_promote( string clan, string id, string level, int money )
{
        int i;
        if( !undefinedp(clans["limit"][level]) && sizeof(clans[clan][level]) > clans["limit"][level] -1 ) // 確定位階
                return 0;
        i = sizeof(LEVEL); // 清掉原先的位階
        while(i--)      {
                if( member_array( id, clans[clan][LEVEL[i]]) == -1 )
                        continue;
                clans[clan][LEVEL[i]] -= ({ id });
                break;
        }
        if( level == "banish" ) { // 將 id 逐出幫派
                clans[clan]["members"] -= ({ id });
                clans[clan]["member_gold"] -= money;
                return 1;
        }
        if( !undefinedp(clans["limit"][level]) ) // level(2~4)
                if( undefinedp(clans[clan][level]) ) // 加入該 level
                        clans[clan][level] = ({ id });
                else
                        clans[clan][level] += ({ id });
        save();
        return 1;
}

int change_clan_master(string clan, string new_master)
{
        // 先將新幫主的舊位址去掉
        clan_promote(clan, new_master, "",0);
        // 設定新幫主
        clans[clan]["master"] = new_master;
        return 1;
}

// 將 clan 幫派的 what 設定成 value, 這個可能對 array 不太好處理
mixed clan_set(string clan, string what, mixed value)
{
        if( undefinedp(clans[clan]) )
                return notify_fail("沒有這個幫派。\n");
        clans[clan][what] = value;
        return value;
}

// 傳回 clan 幫派的 what 值
// 增加可以傳回階級人數 by chan
mixed clan_query( string clan, string what )
{
        if(clan && what && !undefinedp(clans[clan][what]) )
        return clans[clan][what];
        else
        return 0;
}

void dest_clan( string clan_id )
{
        map_delete( clans, clan_id );
        save();
}

// 傳回該玩家幫派的目錄所在
string get_clan_dir( object me )
{
        if( me->query("clan/id") )
                        return CLAN_HOME + me->query("clan/id") + "/";
        return "";
}

//傳回玩家目前待在哪一幫派的地盤上 by ACKY
string what_clan_area(object me)
{
        int i;
        string path;
        path = file_name(environment(me));
        if( path[0..10]=="/open/clan/" )        {
                i = 11;
                while( i++ )
                        if( path[i] == '/' )
                                return path[11..i-1];
        }
        return "NULL";
}

// 確定該玩家所在的房間是他幫派所屬的, return 1 是該玩家的幫派房間
int is_clan_room(object me)
{
        int i;
        string file,roomdir;
        roomdir=get_clan_dir(me)+"room/";

        file    = file_name(environment(me));
        i       = strlen(file);

        while(i--)
                if( file[i] == '/' )
                        break;

        if( file[0..i] == roomdir)
                return 1;
        return 0;
}

// 檢查是否有此幫派 by ACKY
// 有 -> return 1
// 無 -> return 0
int have_clan( string clan_id )
{
        mixed *file;
        file = get_dir("/open/clan/"+clan_id+"/", -1);
        if( !sizeof(file) )
                return 0;
        if( clan_id == "area" || clan_id == "std" )
                return 0;
        return 1;
}

// 檢查玩家 id 是否是 clan 幫派的一員, 是就傳回 1,
// 如果沒 flag 或 flag = 0, 則非幫眾傳回 0
// 如果有 flag 或 flag != 0, 非幫眾則加入該幫派的 members
// return -1 : 如果沒有這個幫派的資料
int is_member_or_add(string clan, string id, int flag)
{
        string *member_list;

        if( undefinedp(clans[clan]) )
                return -1;
        if( !flag )
                return 0;

        if( undefinedp(clans[clan]["members"]) )
                clans[clan]["members"] = ({ id });
        else
                clans[clan]["members"] += ({ id });
        return 1;
}

int clan_data( object me, string clan_name ) //傳回幫派資料 by ACKY
{
        string *clan_id, *clan_data, clan_str;
        int o, sum;
        clan_id = sort_array( CLAN_D->query_all_clan(), "sort_keys", this_object() );
        sum = sizeof( clan_id );
        clan_str = sprintf("目前FS有%d個幫派 -\n", sum );
        for( o=0; o<sum; o++ )
                clan_str += sprintf("[%s] ", clan_id[o] );
        clan_str += "\n";
        me->start_more( clan_str );
        clan_str = sprintf("[%s]", clan_name );
        clan_data = sort_array( keys( clans[clan_name] ), "sort_keys", this_object() );
        sum = sizeof( clan_data );
        for( o=0; o<sum; o++)
                clan_str += sprintf("[%s] %-26O\n", clan_data[o], clans[clan_name][clan_data[o]] );
        me->start_more( clan_str );
        return 1;
}

int sort_keys( string key1, string key2 ) //排列資料 by ACKY
{
  return strcmp( key1, key2 );
}

string *query_all_clan() //傳回幫派資料的關鍵字 by ACKY
{
        return keys(clans);
}

mapping query_all_clans() //傳回幫派全部資料 by ACKY
{
        return clans;
}
// 傳回檔案的最大數字....幫weapon,eq,npc設計的...
// 因為如果沒有的話,刪掉eq時會亂掉....by acky...
// path:幫派的目錄...
// type: "weapon/","armor/","npc/",這三類。..
// name: 就是檔名..like unarmed24,finger23
// by avgirl
int check_last_num(string path,string type,string name)
{
mixed *file;
int i, j;
mixed k=({});
// 取得檔案
        file = get_dir(path+type+name+"*", -1);
        if(!sizeof(file)) return 0;
// 把所有的數字粹取出來
        for(i=0;i<sizeof(file);i++){
if(find_player("avgirl") ) tell_object(find_player("avgirl"),sprintf("物件:%s\n",file[i][0]));
        sscanf(file[i][0],name+"-%d.c",j);
// 把數字加進k 中,會行成k=({1,2,3,4,......})
        k += ({j});
        }
if(find_player("avgirl") ) tell_object(find_player("avgirl"),sprintf("數字:%O\n",k));
// 把最後一個數值傳會去...
 if(find_player("avgirl") ) tell_object(find_player("avgirl"),sprintf("數字:%d\n",sort_array(k,1)[sizeof(k)-1]));
        return sort_array(k,1)[sizeof(k)-1];
}
// 制作任務用item...
// by avgirl...
int list_item(object me )
{
        string *files,list,temp,dir,str,number,err;
        int i,k;

        files = get_dir(get_clan_dir(me) + "item/*.c");
        i = sizeof(files);

                if(i==0) {
                list = sprintf("幫內目前沒有任何任務用物品。\n");
                write(list);
                return 1;
        }
        list = sprintf("幫內目前有%s個任務用物品：\n",CHINESE_D->chinese_number(i));
        write(list);
        for(k=1; k<i+1; k++ ) {
                number=sprintf("%d",k);
                temp = get_clan_dir(me)+"item/item-"+number+".c";
                if(file_size(temp) == -1)       {
                        str="摧毀的物品";
                       i++;
                }
                else {
                  err = catch(temp->query("name"));
                        if(!err)  str=temp->query("name");
                        else str="[1;31m損壞的物品[0m";
                }
                printf("[%2d]%-20s%s", k, str, (k%2 ? "" : "\n") );
        }
    write("\n");
    return 1;
}
