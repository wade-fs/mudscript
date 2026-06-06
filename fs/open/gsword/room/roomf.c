#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
     set("short" ,"仙劍派偏廳");
     set("long", @LONG
這裡是仙劍派的偏廳，通常是長老教誨弟子的地方，同時這裡也記錄
著仙劍派弟子的武功概況，你可以用(list)得知。

LONG
     );
    
     set("exits",([
"north":__DIR__ "g1-1",
]));
     
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
          case "shasword" : i = 2; break;
          case "master" : i = 3; break;
          default: return notify_fail("使用格式: list <種類>\n"
                                      "經驗值(combat_exp)\n"+
                                      "內力(force)\n"+
                                      "仙劍劍術(shasword)\n"+
                                      "師承(master)\n\n");
        }
	user = users();
        me = this_player();
	user = filter_array(user,"filter_family",this_object());
	j=sizeof(user);
        switch(i) {
   	  case 0 : user=sort_array(user,"sort_exp",this_object());
	           str=sprintf(HIG + "仙劍派經驗值排行榜:\n\n" + NOR);
  	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
                   tell_object(this_player(),str);
	           break;
	  case 1 : user=sort_array(user,"sort_force",this_object());
                   str=sprintf(HIG + "仙劍派內力排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
                   tell_object(this_player(),str);
                   break;		   
	  case 2 : user=sort_array(user,"sort_shasword",this_object());         
	           str=sprintf(HIG + "仙劍派劍術排行榜:\n\n" + NOR);
	           for(i=0; i<j; i++)
	              str+=sprintf(HIC + "第%2d名 %30s(%s)\n" + NOR,i+1,user[i]->query("name"),user[i]->query("id"));
	           str+="\n";
	           tell_object(this_player(),str);
		   break;
	  case 3 : str=sprintf(HIG + "仙劍派師徒關係:\n\n" + NOR);
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
  if(family->query("family/family_name") == "仙劍派" && !wizardp(family) && family->query("id")!="appo") return 1;
  return 0; 
}
int sort_exp(object man1, object man2)
{
 int i, j;
 i = man1->query("combat_exp");
 j = man2->query("combat_exp");
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
int sort_force(object man1, object man2)
{
 int i, j;
 i = man1->query("max_force");
 j = man2->query("max_force");
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
int sort_shasword(object man1, object man2)
{
 int i, j;
 i = man1->query_skill("shasword")*10 + man1->query("combat_exp")/10000 + man1->query_skill("sword")*5;
 j = man2->query_skill("shasword")*10 + man2->query("combat_exp")/10000 + man2->query_skill("sword")*5;
 if (i>j) return -1;
 else if (i<j) return 1;
 else return 0;
}
