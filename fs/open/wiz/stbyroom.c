// 網聚獎品替身發放房間!!!
#include <room.h>
#include <ansi.h>
inherit ROOM;
string *user_id_2 = ({
"aspire","zero","amy","pnx","palla","trust","luner","gendor","catbaby","aanswer",
"chritina","madoka","jojowolf","sula","flamer","nakama","lancelin","lunn","libraa",
"hikki","zard","snowcraft","dunga","bloodblade","julio","leon","ddt","victor","kaze",
"lovesui","fee","evilshadow","wasain","guilty","apple","sillyboy","nicklin","aro",
"windows","cyberfight","pzp","copy","ansys","shian","women","namie","chan"
}),*user_id_4 = ({"puffy","smirk","sdgudam","cyr","leing","chan"});
void create ()
{
set ("short",HIC + "網聚獎品『替身』發放處" + NOR);
set ("long","這次網聚共有將近七十位玩家參加!!!!
網聚的獎品單請打help fs_net及help fs_net2
此房間是用來發放網聚替身的房間!!
西邊的房間是發放屬性、技能、內力的房間!!!
東邊是發放魔龍型防具的房間
指令如下：
          get_standby  <領取這次網聚的獎品>

");
  set("no_kill",1);
  set("no_fight",1);
  set("light_up",1);
  set("exits", ([
  "north" : "/open/wiz/fsroom",
  "east"  : "/open/wiz/meqroom.c",
  "west" : "/open/wiz/skill_room",
]));
  setup();
}

void init()
{
add_action("in_standby","get_standby");
}
int in_standby()
{
object me = this_player();
string name=me->query("id");
int i,j,number=sizeof(user_id_2),four=sizeof(user_id_4);
if(!me->query("fs_net3/standby"))
 {
   if(name=="lancelin")
    {
     write("恭喜你得到了三個替身!!!\n");
     me->add("standby",3);
     me->set("fs_net3/standby",1);
     log_file("net/standby", sprintf("%s(%s) 領取網聚替身獎品!!替身三個!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
    }else if(name=="yukigirl")
    {
     write("恭喜你得到了五個替身!!!\n");
     me->add("standby",5);
     me->set("fs_net3/standby",1);
     log_file("net/standby", sprintf("%s(%s) 領取網聚替身獎品!!替身五個!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
    }else if(name=="hgf")
    {
     write("恭喜你得到了十三個替身!!!\n");
     me->add("standby",13);
     me->set("fs_net3/standby",1);
     log_file("net/standby", sprintf("%s(%s) 領取網聚替身獎品!!替身十三個!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
    }
   for (j=0; j<number; j++)
    if(user_id_2[j] == name)
     {
     write("恭喜你得到了二個替身!!!\n");
     me->add("standby",2);
     me->set("fs_net3/standby",1);
     log_file("net/standby", sprintf("%s(%s) 領取網聚替身獎品!!替身二個!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
     }
   for(j=0;j<four;j++)
    if(user_id_4[j]==name)
     {
     write("恭喜你得到了四個替身!!!\n");
     me->add("standby",4);
     me->set("fs_net3/standby",1);
     log_file("net/standby", sprintf("%s(%s) 領取網聚替身獎品!!替身四個!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
     return 1;
     }
    write("sorry!!你並不在名單上!!!\n");
    return 1;
 }
    write("你以經領了!!!\n");
    return 1;
}
