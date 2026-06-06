
// by roger

inherit NPC;
#include <ansi.h>
int do_acc();
void create()
{      
        set("title","仙劍派第二代弟子");
        set_name("風青雲",({"yan"}));
        set("nickname",HIR + "劍如迴陽" + NOR);
        set("class","swordsman");
        create_family("仙劍派",2,"弟子");
        set("family/master_name","逍遙子");
        set("gender","男性");
        set("age",87);
        set("str",30);
        set("long","他是仙劍派第二代弟子，鄭士欣之師叔。\n");   
        set("inquiry",([  
        ]));
        set("combat_exp",1000000);
        set("max_gin",3000);
        set("gin",3000);
        set("max_kee",3000);
        set("kee",3000);
        set("max_sen",3000);
        set("sen",3000);
        set_skill("dodge",400);
        set_skill("unarmed",400);
        set_skill("parry",400);

        setup();
        add_money("gold",5);
}
int accept_fight(object who)
{
 return notify_fail("風青雲疑惑的說:你不是來救我嗎？\n");
}
int accept_kill(object who)
{
 return notify_fail("風青雲疑惑的說:你不是來救我嗎？\n");
}
void init() {
  object obj;
  ::init();
  if(interactive(obj=this_player()) && !is_fighting()) 
     {
      remove_call_out("greeting");
      call_out("greeting",1,obj);
     }
add_action("do_recover","recover");
}
void greeting(object ob)
{
        command("hmm");
}
int do_recover(string str)
{
 object me;
 me=this_player();
 if(str!="force"){
   tell_object(me,"你想做什麼??\n");
   return 1;
                }
 //增加exp check避免仙劍利用team的方式kill king避開殺king要250 one的限制               
 if(me->query_temp("win_fireking")!=1 || me->query("combat_exp") < 2500000)
 { 
   message_vision("$N以解穴手法在風青雲的大穴上點了幾下，但毫無效果。\n",me);
   return 1;
 }
 else{ 
   message_vision(HIY + "$N以焚天魔王所授的獨門解穴法在風青雲的大穴上點了幾下...\n" + NOR,me);
   call_out("quests",1,me);
   return 1;
     }
}

void quests(object me)
{
   write("\n風青雲一聲大喝，全身骨節山響而起，被點的三元大穴已被全數衝破！\n");
   call_out("mes1",1,me);
}   
void mes1(object me)
{
 if(me->query("family/family_name")=="仙劍派"){
   message_vision(HIY + "風青雲對$N說：多謝你替我解穴，讓我的內力得以再度貫通
周身一百零八大穴。既然是本門弟子，就讓我告訴你一件本門
的故事
" + NOR,me);
   me->set("quest/sun_fire_sword",1);
   call_out("mes2",2,me);
                                    }
 else {
message_vision(HIY + "風青雲對$N說：多謝你替我解穴，讓我的內力得以再度貫通
周身一百零八大穴。但你我職業不同，我的劍招絕學你也無法
領悟。這樣好了，我另外知道另一件護甲寶物的鑄法，你去找
魔界村的「李昆陽」告訴他「護甲寶物」的製法，也\許\他能幫
你也說不定。
" + NOR,me);
  me->set("quest/save_yan",1);
      }
}
void mes2(object me)
{ 
 write("
風青雲說：逍遙子祖師曾經發展出另一套劍法絕學，但並沒有來得及傳完全部
的精髓便告失蹤，這些只有基礎部分的劍術就是目前的仙劍禁斷之連陽七訣。
其實在他失蹤前曾把這套劍術寫成劍譜，現在就在我的身上。繼然你是仙劍弟
子又救過我性命，那這本劍譜就傳給你參習吧!(欲知詳情請打help 連陽七訣劍法)
\n");

new("/autoload/swordsman/sun_sword_book")->move(me);
 me->set("quest/sun_fire_sword",1);
 me->set("title","仙劍派絕代劍俠");
}
