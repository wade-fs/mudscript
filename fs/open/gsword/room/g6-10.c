#include <room.h>

 inherit ROOM;
 void receive_hit();
 int done=0;
 void create()
{
        set("short", "仙劍派禁地");
        set("long", @LONG
眼前是一個偌大的山洞，門口以精鋼柵欄封住，洞內黑戚戚的一片，
完全不能探知裡面說不出的詭異氣氛，時有聽到動物慘叫的聲音，時而聞
到濃厚的血腥味道令你不寒而顫。洞口的左側有個拉桿(level)。
 
LONG
        );

             
        set("item_desc",(["level":
 "這個拉桿已生銹多年，似乎是用來開啟柵門用的，你可以試著拉(pull)動它。\n",
 ]));
                                        
       set("exits",([
                     "east":__DIR__"g6-9",
                     ]));
                    
           setup();
        }

void init()
{
add_action("pull_level","pull");
}

int pull_level(string str)
{
   if( done==1)
     return notify_fail("機關已經啟動\n");
   if(str!="level")
     {
         return notify_fail("你要拉什麼??\n");
         }
     write(" 喀啦一聲～～～～～～\n
            柵門漸漸的升起.\n");
     write("\n");
    done=1;
    receive_hit();
    return 1;
 }
 
 void receive_hit()
 {
 object ob;
 object hitter;
 write("突然一位老者挾者萬均之勢從天而降,手中長劍幻化成無數劍氣向你而來\n");
 message_vision(sprintf("老者喝道:擅闖仙劍禁地者,死!!!\n"),this_player());
 ob=new("/open/gsword/npc/guard");
 hitter=this_player();
 ob->move(environment(this_player()));
 ob->invocation(this_object());
 ob->kill_ob(hitter);
 set("exits",([
     "east":__DIR__"g6-9",
    "north":__DIR__"g6-11"
    ]));
  }
int valid_leave(object me,string dir)
{
  if (dir=="north" && present ("oldman", environment(me)))
      return notify_fail ("老者擋著你說道: 想闖禁地,先問問我手上的這把劍吧。\n");
        return ::valid_leave(me, dir);
}     
     
     
     
        
