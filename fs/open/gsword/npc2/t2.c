#include <ansi.h>
inherit NPC;
string ask_test();
string ask_test1();

void create()
{
        set_name(HIW + "第二試煉者" + NOR, ({ "testman"}) );
        set("gender", "男性" );
        set("age", 158);
        set("int", 26);
set("long","傳說中專門鍛鍊仙劍派門人的守護者..你可以問他有關試煉的事。\n");
        set("inquiry",([
        "試煉":(:ask_test:),
        "試煉印記":(:ask_test1:),

        ]));
        set("combat_exp",50000);
        set("max_kee",500);
        set("max_gin",500);
        set_skill("unarmed",50);
        set_skill("parry",50);
        set_skill("force",50);
        setup();
   }

string ask_test()
{
if (this_player()->query("quests/yantestmark1")==1&&this_player()->query("quests/yantestmark2")==1 &&this_player()->query("quests/yantestmark3")==1&& this_player()->query("quests/yan")==3)
 {
  this_player()->set("quests/yan",4);
  tell_object(this_player(),HIW + "你已經通過第二試驗了.所以我送你到第三試煉區去吧.\n" + NOR);  
  message("system",this_player()->name()+HIW"通過仙劍第二試煉。\n" + NOR,users());
  this_player()->delete("quests/yantestmark1");
  this_player()->set("title","仙劍第二試煉劍俠");
  this_player()->delete("quests/yantestmark2");
  this_player()->delete("quests/yantestmark3");  
  this_player()->delete("quests/2ndtest");
  this_player()->move("/open/gsword/room2/shab1.c"); 
}
else if (this_player()->query("quests/yan")>3)
{
  tell_object(this_player(),HIW + "你已經通過第二試驗了.所以我送你到第三試煉區去吧.\n" + NOR); 
  this_player()->move("/open/gsword/room2/shab1.c"); 
}
else
 {
  tell_object(this_player(),HIW + "第二試驗的目的在於鍛鍊你的注意力.\n因此你由北方回到蜀山..並由蜀山附近找到三個試煉印記.之後才算過關\n" + NOR);
  return (HIW + "至於如何去找..這你就要多費心了...\n" + NOR);
 }

}

string ask_test1()
{
  tell_object(this_player(),HIW + "我只知道其中一個是好像在展伯承身上,另兩個..你就要仔細的去找找了..\n" + NOR); 
  return (HIW + "不過我可以瞞著wiz 跟你說.主要的印記都在quest 人物的身上..你可以去跟他們問問試煉印記的事\n" + NOR);
 }

