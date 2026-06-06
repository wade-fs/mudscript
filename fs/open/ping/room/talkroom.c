inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short",HIC + "段家交流廳" + NOR);
  set ("long", @LONG

一進大廳，廳上掛著一赤金盤龍大匾，上頭寫著斗大的四個字『 段家
無敵』。大廳中擺著一塊Board，是段家弟子互相交流的地方。左邊則
是一塊木板，上面刻有段家弟子的排行榜，可用list來看排行榜。



LONG);

  set("exits", ([ /* sizeof() == 3 */
  "home" : "/open/ping/room/p1",
  "down" : "/open/ping/room/tr1",
]));

  set("light_up", 1);
  set("valid_startroom",1);
  set("no_clean_up", 1);
  set("no_kill", 1);
  set("no_fight", 1);
  set("no_magic", 1);
                        
  setup();
  call_other("/obj/board/lord_b.c","????");
}



void init() {
        add_action("do_billing","list");
}

int do_billing(string str) {
        object *user,me,master;
        int i,j;
        switch(str) {
          case "combat_exp" : i = 0; break;
          case "force" : i = 1; break;
          case "six-fingers" : i = 2; break;
          case "master" : i = 3; break;
          default: return notify_fail("使用格式: list <種類>\n"
                                      "經驗值(combat_exp)\n"+
                                      "內力(force)\n"+
				      "六脈神劍(six-fingers)\n"+
                                      "師承(master)\n\n");
        }
        user = users();
        me = this_player();
        user = filter_array(user,"filter_family",this_object());
	j=sizeof(user);
        switch(i) {
  	  case 0 : user=sort_array(user,"sort_exp",this_object());
	           str=sprintf(HIG + "段家經驗值排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 1 : user=sort_array(user,"sort_force",this_object());
	           str=sprintf(HIG + "段家內力排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 2 : user=sort_array(user,"sort_sixfinger",this_object());
                   str=sprintf(HIG + "段家六脈神劍排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
	           tell_object(this_player(),str);
		   break;
          case 3 : str=sprintf(HIG + "段家師徒關係:\n\n" + NOR);
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
 if(family->query("family/family_name") == "段家" && !wizardp(family)) return 1;
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
int sort_sixfinger(object man1, object man2)
{
 int i,j;
 i = man1->query_skill("six-fingers");
 j = man2->query_skill("six-fingers");
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
