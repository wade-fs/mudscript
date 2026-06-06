// Room: /u/f/fire/room/room1-31.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  seteuid(getuid());
  set ("short",HIY + "射手派廣義堂" + NOR);
	set( "build", 27 );
  set ("long", @LONG
漫長的道路，終於來到了這裡。你似乎可以感覺到這裏的氣氛比
其他地方不一樣。你發現你的眼前似乎站著一位十分高人的人物，他
就是射日派第二代掌門人--->李廣。他的眼中散發出剛強不拔之氣息
堅定的目光使你突然嚴肅，左邊則是一塊木板，上面刻有射日派弟子
的排行，可用list來看排行。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room1-24",
  "west" : __DIR__"room1-30.c",
  "east" : __DIR__"room1-29.c",
"up" : __DIR__"eq-room",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/marksman/npc/master_t.c" : 1,
]));
  set("valid_startroom", 1);
set("light_up",1);

call_other("/obj/board/marksman_b","???");
  setup();
}
void init()
{
	        add_action("do_billing","list");
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
                   str=sprintf(HIG + "射日派經驗值排行榜:\n\n" + NOR);
                   for(i=0; i<j; i++)
                      str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
                   str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 1 : user=sort_array(user,"sort_force",this_object());
                   str=sprintf(HIG + "射日派內力排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 2 : str=sprintf(HIG + "射日派師徒關係:\n\n" + NOR);
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
 if(family->query("family/family_name") == "射日派" && !wizardp(family)) return 1;
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
