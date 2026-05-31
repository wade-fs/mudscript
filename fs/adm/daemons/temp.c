#include <ansi.h>
inherit F_SAVE;
mapping *records;
#define SAVE_FILE "/data/bss_record/heart"

string query_save_file() {
 return SAVE_FILE;
}

void create() { seteuid(getuid());}
void record_heart_beat(object user)
{
        object *user_enemy,user_location;
        mapping record;
        string where,f;
        int i;

        if(user->query_temp("have_no_heart_beat"))
        return ;
        if(!user->query("id")) return;
        restore();
        user->set_temp("have_no_heart_beat",1);
        user_location=environment(user);
        user_enemy=user->query_enemy();
        if(user_location) where=file_name(user_location)+" "+user_location->query("short");
        if(user->is_fighting()) f="fighting";
        else f="no fighting";
        if(geteuid(user)==0) return ;
        record = ([
                "id":geteuid(user),
                "name": user->name(1),
                "place": where,
                "time": ctime(time()),
                "fighting?": f,
                "enemy": sprintf("%O",user_enemy)
        ]);
        if( !pointerp(records) ) records = ({ record });
        else records += ({ record });
        save();

        return ;
}

string check_heart_beat(string str)
{
  int i,flag;
  string out="";

  flag=0;
  if(!str) return "check_no_heart_beat 玩家id\n";
  restore();
  if( !pointerp(records) || !sizeof(records) ) {
    return "目前沒有任何人有沒心跳的記錄。\n";
  }
  for(i=0;i<sizeof(records);i++)
  {
        if(str!=records[i]["id"]) continue;
        flag=1;
        out+=sprintf("id=%s\n",records[i]["id"]);
        out+=sprintf("name=%s\n",records[i]["name"]);
        out+=sprintf("所在地=%s\n",records[i]["place"]);
        if(records[i]["fighting?"]=="fighting")
        {
                out+=sprintf("正在戰鬥!!!\n");
                out+=sprintf("對像有%s\n",records[i]["enemy"]);
        }
        else
        {
                out+=sprintf("沒有在戰鬥!!!\n");
        }
        out+=sprintf("時間為%s\n",records[i]["time"]);
        out+=sprintf("*************************************\n");
  }
  if(!flag)
  out+=sprintf("%s這個人並沒有失去心跳過的記錄!!!\n",str);

  return out;
}

