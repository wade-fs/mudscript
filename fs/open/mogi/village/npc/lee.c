// by roger
// add by appo
inherit NPC;
#include <ansi.h>
string ask_tesin();
void do_acc();
void do_acc1();
void do_acc2();
void make_sword();
void create()
{      
        set("nickname","巧奪天工");
        set_name("李昆陽",({"lee"}));
        set("gender","男性");
        set("age",58);
        set("str",30);
        set("long","
一個孤獨的老人，在魔界村裡打造一些兵器和防具為生。由於魔界村的人常常
要出魔界村去冒險，因此兵器和護具的需求也蠻大的。不過仔細一看他的眼神
精光內斂，打鐵的手法更隱隱約約有武功\的影子，且穩健異常顯示他的內力修
為非常深厚。難道他的過去有什麼驚人的藝業嗎?
\n");   
        set("inquiry",([
        "迅雷劍" : (:do_acc:),
        "龍鐵心" : (:ask_tesin:),
        "護甲寶物" : (:do_acc1:),       
        "過去" : (:do_acc2:),  
        ]));
        add_action("do_acc","acc");
        set("combat_exp",1000000);
        set("max_gin",3000);
        set("max_kee",3000);
        set("max_sen",3000);
        set("max_force",3000);
        set("force",5000);
        setup();
}
int accept_fight(object who)
{
 return notify_fail("李昆陽說:老夫很久不動手啦...\n");
}
int accept_kill(object who)
{
 return notify_fail("李昆陽說:老夫很久不動手啦...\n");
}

void do_acc()
{
object me;
me = this_player();
    if(me->query("quest/tunder_sword")!=1)
    command("say 聽說有這把劍，不過鑄法已失傳了。");
                                           
    else{
         if(!present("tunder_sword",me)){
    command("say 什麼...這...你竟然知道鑄法...難以相信啊..");
    command("say 你等著，讓老夫為你打造這把早已失傳的劍!");
    tell_object(me,HIY + "李昆陽的眼睛突然精光暴射...\n" + NOR);
    tell_object(me,HIY + "李昆陽開始燒鐵鑄劍...\n" + NOR);
    tell_object(me,HIB + "屋裡忽然藍光隱隱....\n" + NOR);
    command("say 唉...終於鑄好了...花了我畢生的功\力...");
    command("say 拿去吧，望你憑藉此劍斬妖除魔!!");
    new("/daemon/class/swordsman/obj/tunsword")->move(me);  
                                        }
         else command("say 你不是已經有一把了??");             
        }
}

void do_acc2()
{
object me;
me = this_player();
    if(me->query("family/family_name")=="仙劍派"){
   command("sigh");
   command("你是仙劍派的吧?告訴你吧，我是第二代掌門的師弟的秘密弟子");
   command("say 我師父就是風清揚!");
   
                                     
      
                                                 }
}

void do_acc1()
{
 object me;
 me=this_player();
   if(me->query("quest/save_yan")!=1)
     command("say 你在說什麼?");
                                     
   else{
     if(present("gold hat",me)) command("say 你不是已經有了??");

                              
     else if(me->query("bank/coin",1)<500000) command("say 這護甲很貴，你的存款不足以支付(需50兩黃金)");
                                         
     else{
     command("say 沒問題，馬上打給你");      
     tell_object(me,HIY + "李昆陽給你一頂金翅朝天冠\n" + NOR);
     me->add("bank/coin",-500000);
     new("/open/mogi/castle/obj/gold-hat")->move(me);
         }
       }
}
 string ask_tesin()
{
if (this_player()->query("quests/shasword")==5)
{
 if (this_player()->query_temp("find_tesin2")==1)
  {
  this_player()->set_temp("find_tesin",1);
  return ("聳了聳肩﹐很抱歉地說﹕無可奉告。");
  }
 if (this_player()->query_temp("find_tesin2")==2)
  {
  this_player()->set_temp("find_tesin",2);
  return ("龍鐵心...沒聽過ㄝ.");
  }
 if (this_player()->query_temp("find_tesin2")==3)
  {
  this_player()->set_temp("find_tesin",3);
  return ("嗯..這個嘛..嗯~~。");
 }
 if (this_player()->query_temp("find_tesin2")==4)
  {
  this_player()->set_temp("find_tesin",4);
  return ("嗯..這個嘛..嗯~~。");
  }
 if (this_player()->query_temp("find_tesin2")==5)
  {
  this_player()->set_temp("find_tesin",5);
  return ("阿..我不知道啦..煩不煩阿 一直問...我都煩死了~~。");
  }
 if (this_player()->query_temp("find_tesin2")==6)
  {
  this_player()->set_temp("find_tesin",6);
  return ("你去找別人吧..這..我實在是不敢跟你說。");
  }
 if (this_player()->query_temp("find_tesin2")==7)
 {
  this_player()->set_temp("find_tesin3",1);
  return ("我這的東西都是龍鐵心教我做的.至於龍鐵心在哪..我就不知道了..");
 }
}
}







