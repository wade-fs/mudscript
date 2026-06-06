#include <room.h>

 inherit ROOM;
void receive_hit();
 void create()
{
        set("short", "仙劍派禁地");
        set("long", @LONG
這是仙劍派的禁地,但是放眼望去,這兒跟一般的岩石平臺沒啥兩樣,
景物也是稀疏平凡得很,到底為什麼這兒被仙劍派列為禁地,嚴禁弟
子及訪客接近,就真要說這有特異之處的話,大概也只是在左邊有一
棵上百年非要十人才能圍抱巨木(Gaint tree)吧!!


LONG
        );

        
        set("item_desc",(["Gaint tree":
 "這是一棵百餘年的古樹,藤蔓佈滿了整個樹身,翻開藤蔓一看,一個掌印(hand_print)嵌入
 樹身,定是高人所為,神往之餘,你好想也對著掌印來上一掌(hit hand_print)幻想你是以前
 的那位高人.\n",
 "hand_print" :
 "這個掌印足足有五寸寬三寸厚,簡直令人匪夷所思\n"
 ]));
                                        
       set("exits",([
                     "south": "/u/b/bigcat/room/rroad4.c"
                     ]));
                    
                    
           setup();
        }

void init()
{
add_action("hit_hand_print","hit");
}

int hit_hand_print(string str)
{
   if(str!="hand_print")
     {
         return 0;
         }
     write(" 喀啦一聲～～～～～～,你本能性的緊握武器,防備突如奇來攻擊\n
           ～～～～～\n");
     write("\n");
    receive_hit();
    return 1;
 }
 
 void receive_hit()
 {
 object ob;
 object hitter;
 write("突然一位老者挾者萬均之勢從天而降,手中長劍幻化成無數劍氣向你而來\n");
 message_vision(sprintf("老者喝道:擅闖仙劍禁地者,死!!!\n"),this_player());
 ob=new("/u/b/bigcat/mob/guard");
 hitter=this_player();
 ob->move(environment(this_player()));
 ob->invocation(this_object());
 ob->kill_ob(hitter);
 set("exits",([
"enter": "/u/b/bigcat/room/tree",
"south": "/u/b/bigcat/room/rroad4"
   ]));
  }
int valid_leave(object me,string dir)
{
  if (dir=="enter" && present ("oldman", environment(me)))
      return notify_fail ("老者擋著你說道: 想闖禁地,先問問我手上的這把劍吧。\n");
        return ::valid_leave(me, dir);
}     
