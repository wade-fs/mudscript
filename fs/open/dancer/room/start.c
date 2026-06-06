//room:/open/dancer/room/start.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{

  string long;
  set ("short", HIY "夜夢殿堂" NOR );
  set( "build", 189 );

long = ""+
"                        "HIY"夜夢殿堂"NOR"      \n"+
"\n"+
"      這裡是夜夢小築的大殿"HIC"《"HIY"夜夢殿堂"HIC"》"NOR"，這裡是夜夢弟子們平常\n"+
"  學習舞蹈、武術的地方，建築得美侖美煥，美麗的建築再加上舞者\n"+
"  們優美的舞蹈，真是會令人以為身處幻境。往西則是舞者專用的聊\n"+
"  天休息室喔！\n"+
"  右邊釘了一塊木板(list)，此外也可試著在這跳舞(dancing)。\n\n";

  set("long", long);
  set("light_up", 1);
  set("valid_startroom", 1);
  set("exits", ([ /* sizeof() == 3 */
  "south"     :"/open/dancer/room/rooms1.c",
  "east"      :"/open/dancer/room/roome1.c",
  "west"      :"/open/dancer/room/cafeteria.c",

  ]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/dancer/npc/master_yua.c":1,
  ]));

  setup();
  call_other("/obj/board/dancer_b.c","????");
}

int valid_leave(object me, string dir)
{
  if(me->query("class")!="dancer"&&dir=="west")
    return notify_fail("喔喔！那裡只有舞者才能進去喲～\n");
  return ::valid_leave(me,dir);
}

void init()
{
  add_action("do_dancing","dancing");
  add_action("do_billing","list");  
}

int do_dancing()
{
  object me;
  me = this_player();
  if(me->query("class")!="dancer")
    return notify_fail("喔喔！這個只有舞者才能用喲～\n");
  me->move("/open/trans/room/room4");
  return 1;
}

int do_billing(string str)
{
  object *user,me,master;
  int i,j;
  switch(str) {
    case "combat_exp" : i = 0; break;
    case "force" : i = 1; break;
    case "master" : i = 2; break;
    default: return notify_fail("使用格式: list <種類>\n"
                                "經驗值(combat_exp)\n"+
                                "內力(force)\n"+
                                "師承(master)\n\n");
  }
  user = users();
  me = this_player();
  user = filter_array(user,"filter_family",this_object());
  j=sizeof(user);
  switch(i) {
    case 0 : user=sort_array(user,"sort_exp",this_object());
             str=sprintf(HIG"夜夢小築經驗值排行榜:\n\n"NOR);
             for(i=0; i<j; i++)
               { str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id")); }
             str+="\n";
             tell_object(this_player(),str);
             break;
    case 1 : user=sort_array(user,"sort_force",this_object());
             str=sprintf(HIG"夜夢小築內力排行榜:\n\n"NOR);
             for(i=0; i<j; i++)
               { str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id")); }
             str+="\n";
             tell_object(this_player(),str);
             break;
    case 2 : str=sprintf(HIG"夜夢小築師徒關係:\n\n"NOR);
             for(i=0; i<j; i++) {
               if( user[i]->query("family/master_is_ppl") ) {
                 if( master=find_player(user[i]->query("family/master_id"))) {
                   if( master->query("name") != user[i]->query("family/master_name")) {
                     user[i]->set("family/master_name",master->query("name")); }
                 }
                 else {
                   if( master=FINGER_D->acquire_login_ob(user[i]->query("family/master_id"))) {
                     if( master->query("name") != user[i]->query("family/master_name")) {
                       user[i]->set("family/master_name",master->query("name")); }
                     destruct(master);
                   }
                 }
               }
               str+=sprintf(HIC"%|20s(%|10s)     師承  %|20s(%|10s)\n"NOR,user[i]->query("name"),user[i]->query("id"),user[i]->query("family/master_name"),user[i]->query("family/master_id"));
             }
             str+="\n";
             tell_object(this_player(),str);
             break;
  }
  return 1;
}

int filter_family(object family)
{
  if(family->query("family/family_name") == "夜夢小築" && !wizardp(family)) return 1;
  return 0; 
}

int sort_exp(object man1, object man2)
{
  int i,j;
  i = man1->query("combat_exp");
  j = man2->query("combat_exp");
  if (i>j) return -1;
  else if (i<j) return 1;
  else return 0;
}

int sort_force(object man1, object man2)
{
  int i,j;
  i = man1->query("max_force");
  j = man2->query("max_force");
  if (i>j) return -1;
  else if (i<j) return 1;
  else return 0;
}
