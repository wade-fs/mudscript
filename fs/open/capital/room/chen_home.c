// Room: /open/capital/room/r69.c
#include "../../open.h"
#include <ansi.h>
inherit ROOM;

void create ()
{
    set("short",HIC"大理寺"NOR);
	set( "build", 62 );
  set ("long", @LONG
這裡就是全國最高的司法機構「大理寺」﹐這裡專門處裡一些重大案件
﹐以及審理所有隸屬於大理寺的各司法部門﹐在這裡不管是王公貴族﹐還是
朝廷重臣﹐只要犯了罪﹐都會秉公處理﹐絕不會循私，左邊有一塊記錄排行
的木板(list)。
 
LONG);

  set("exits", ([ /* sizeof() == 1 */
   "south":"/open/capital/room/r15",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/officer/master_chen":1,
   "/open/capital/npc/catcher":2,
]));
  set("valid_startroom",1);
/*
  set("no_fight", 1);


  set("no_magic", 1);
*/
  set("light_up", 1);
  setup();
  call_other("/obj/board/chen_b.c","???");
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
                   str=sprintf(HIG"朝廷命官經驗值排行榜:\n\n"NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 1 : user=sort_array(user,"sort_force",this_object());
                   str=sprintf(HIG"朝廷命官內力排行榜:\n\n"NOR);
                   for(i=0; i<j; i++)
                      str+=sprintf(HIC"第%2d名 %30s(%s)\n"NOR,i+1,user[i]->query("title"),user[i]->query("name"),user[i]->query("id"));
                   str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 2 : str=sprintf(HIG"朝廷命官師徒關係:\n\n"NOR);
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
 if(family->query("family/family_name") == "陳知衡" && !wizardp(family)) return 1;
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
