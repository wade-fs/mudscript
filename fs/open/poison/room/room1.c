#include <ansi.h>
#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "魔教冥蠱魔殿");
  set ("long", @LONG
這裡便是令武林中人聞風喪膽的冥蠱魔教總地，殿內按
五行八卦立了數根飛龍雲柱，地上鋪有大紅地毯，中間則擺
有九龍太座和一塊石版(list)，冥蠱魔教便高坐其上，太座
後石壁上刻有巨幅的聖火像，像徵此魔教聖潔的精神。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "up" : __DIR__"eqroom.c",
  "west" : __DIR__"room17",
  "south" : __DIR__"room7",
  "east" : __DIR__"room18",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 3 */
  "/open/poison/npc/jadegirl" : 1,
  "/open/poison/npc/masterl" : 1,
  "/open/poison/npc/goldchild" : 1,
]));
  set("valid_startroom", 1);

  setup();
call_other("/obj/board/poisoner_b","???");
}
void reset()
{
 set("been_get",0);
 :: reset();
}
void init()
{
  add_action("do_steal","steal");
  add_action("do_billing","list");  
}
int do_steal(string str)
{
  object me = this_player();
  object pearl, guard;
  int lv = me->query_skill("dodge");
  if( str != "pearl" )
	return notify_fail("你想偷些什麼?\n");
  if(query("been_get"))
        return notify_fail("魔教此時戒備森嚴，你沒有下手機會。\n");
  if( random(lv) > random(50))
    {
      tell_object(me,"你順利拿到一顆夜明珠。\n");
      pearl = new("/open/poison/obj/pearl");
      pearl->move(me);
      set("been_get",1);
      return 1;
    }
  else
    {
     set("been_get",1);
      tell_object(me,"啊! 你不小心失手啦。\n");
      message_vision("$N行竊不小心被發現，引來守衛們。\n",me);
      guard = new(POISON_NPC"guard1");
      guard->move(POISON_ROOM"room1");
      guard->kill_ob(me);
      guard->set_leader(this_player());
      guard = new(POISON_NPC"guard1");
      guard->move(POISON_ROOM"room1");
      guard->kill_ob(me);
      guard->set_leader(this_player());
      return 1;
    }
  return 1;
}
int valid_leave(object me, string dir)
{
if (dir == "up" && me ->query("class") != "poisoner")
     return notify_fail("喂 ,進去幹麻 ?想被毒啊。\n");
     return :: valid_leave(me, dir);
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
                   str=sprintf(HIG + "冥蠱魔教經驗值排行榜:\n\n" + NOR);
                   for(i=0; i<j; i++)
                      str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
                   str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 1 : user=sort_array(user,"sort_force",this_object());
                   str=sprintf(HIG + "冥蠱魔教內力排行榜:\n\n" + NOR);
                   for(i=0; i<j; i++)
                      str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
                   str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 2 : str=sprintf(HIG + "冥蠱魔教師徒關係:\n\n" + NOR);
                   for(i=0; i<j; i++) {
	              if( user[i]->query("family/master_is_ppl") ) {
	                if( master=find_player(user[i]->query("family/master_id"))) {
	                  if( master->query("name") != user[i]->query("family/master_name"))
		            user[i]->set("family/master_name",master->query("name"));
	                }
	                else {
	                  if( master=FINGER_D->acquire_login_ob(user[i]->query("family/master_id"))) {
		            if( master->query("name") != user[i]->query("family/master_name"))
		              user[i]->set("family/master_name",master->query("name"));
                            destruct(master);
                          }
	                }
	              }
                      str+=sprintf(HIC + "%|20s(%|10s)     師承  %|20s(%|10s)\n" + NOR,user[i]->query("name"),user[i]->query("id"),user[i]->query("family/master_name"),user[i]->query("family/master_id"));
	           }
                   str+="\n";
	           tell_object(this_player(),str);
		   break;
        }
        return 1;
}

int filter_family(object family)
{
 if(family->query("family/family_name") == "冥蠱魔教" && !wizardp(family)) return 1;
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
