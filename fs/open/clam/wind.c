#include <room.h>

inherit ROOM;

void create ()
{
     set("short" ,"風雷幫幫派大廳");
     set("long", @LONG
這裡是風雷幫的大廳，通常是幫派人員討論的地方，同時這裡也記錄
著風雷幫幫眾的點點滴滴。

LONG
     );
    
  set("light_up", 1);
  set("valid_startroom", 1);
  set("no_fight",1);

set("exits",([
"down":"/open/common/room/inn",
]));
     
     setup();

  call_other("/obj/board/clam_1", "?????");
}
void init()
{
add_action("list_array","list");
}
int list_array(string str)
{
int i,j=0;
int n;
object *glist;
glist=users();
n=sizeof(glist);
sort_array(glist,"list_skill",this_object());
message_vision("風雷幫能力排行榜\n",this_player());
message_vision("--------------\n",this_player());
 for(i=n-1;i>0;i--)
  {
    if(glist[i]->query("clam")=="風雷幫")
      {
        j++;
        message_vision("第"+chinese_number(j)+"名是"+    glist[i]->name()+"\n",this_player());
        
      }
   }
   
return 1;
}

int list_skill( object man1, object man2)
{
 int   i, j;
  
 i = man1->query("combat_exp",1);
 j = man2->query("combat_exp",1);
 if (i>j) return -1;
    else if (i<j) return 1;
     else return 0;
   }  
     
