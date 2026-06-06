#include <ansi.h>
inherit NPC;
string ask_test();
string ask_train();

void create()
{
        set_name(HIW + "第一試煉者" + NOR, ({ "testman"}) );
        set("gender", "男性" );
        set("age", 63);
        set("int", 26);
set("long","傳說中專門鍛鍊仙劍派門人的守護者..你可以問他有關試煉的事。\n你亦可以詢問他你還需要訓練多久(ask testman about train)。\n");
        set("inquiry",([
        "試煉":(:ask_test:),
        "train" : (:ask_train:),

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
if (this_player()->query("quests/test")>199&& this_player()->query("quests/yan")==2)
 {
  this_player()->set("quests/yan",3);
  tell_object(this_player(),HIW + "你已經通過第一試驗了.所以我送你到第二試煉區去吧.\n" + NOR);  
  message("system",this_player()->name()+HIW + "通過仙劍第一試煉。\n" + NOR,users());
  this_player()->set("title","仙劍第一試煉劍俠");
  this_player()->move("/open/gsword/room2/shaa1.c"); 
}
else if(this_player()->query("quests/yan")>2) {
  tell_object(this_player(),HIW + "你已經通過第一試驗了.所以我送你到第二試煉區去吧.
\n" + NOR);
  this_player()->move("/open/gsword/room2/shaa1.c");
}
else
{
tell_object(this_player(),HIW + "第一試驗的目的在於鍛鍊你對仙劍武術的認知及了解..\n" + NOR);
 return (HIW + "因此你得往北方前進..並在試煉山谷中打倒200個試煉武者才行\n" + NOR);
 }

}
string ask_train()
{

 int num;
 num=this_player()->query("quests/test",1);
 if (num<200)
   return sprintf("閣下目前打倒了%d個試煉武者 ,再加油吧!\n",num);
 else 
 return sprintf("閣下已經具有通過第一試煉的資格了..你可以再向我詢問一次有關試煉的事!");
 }
