inherit NPC;
#include <ansi.h>
string do_ans();
string do_ep7();
string do_ep8();
string do_fb3();
string do_fb4();
void create()
{
    set_name("老人", ({ "old man","man","old" }) );
    set("gender", "男性" );
    set("age",70);
    set("str",35);
    set("cor",45);
    set("cps",25);
    set("int",15);
    set("long","他是一個很像外地來的老人, 不斷的在喃喃自語,你不妨聽聽他在說什麼.\n");
    set("combat_exp",1000000);
    set("attitude", "peaceful");
   set("chat_chance", 25);
set("chat_chance_combat", 100);
    set("chat_msg", ({
            "老人說道: 隔世村真是個好地方....\n",
            "老人說道: 可以安心在這邊生活....\n",
            "老人說道: 不曉得「那一位」最近過的怎麼樣了....\n",
        }) );
    set("inquiry",([
                    "那一位" : "喔....哪一位啊, 我不知道, 你是那一位派來的嗎??我「離開」很久了!!",
                    "離開"     : "我離開那個「鬼地方」很久了!!什麼都不知道, 不知道",
                    "前任教主"     : "我什麼都不想說...去問別人吧....",
                    "鬼地方" : (: do_ans :), 
                    "妖女" : (: do_ep7() :), 
                    "老教主" : (: do_ep8() :), 
                    "伍元" : (: do_fb3() :), 
                    "往事" : (: do_fb4() :), 

        ]));

    set_skill("parry", 15);
    set_skill("dodge", 5);
    set_skill("force",300);
        set_skill("poisonforce",300);
        map_skill("force","poisonforce");

    setup();
        add_money("cash",20);

 }      

void init()
{
add_action("do_report","report");
add_action("do_change","change");
}

int do_report(string str)
{
object me=this_player();
object ob=this_object();
if(!str || str !="碧海青天夜夜深" )
{
  tell_object(me,"老人沒有什麼反應");
  return 1;
}
if(me->query_temp("go_oldman_report")==1 && me->query("class")=="poisoner"
&& me->query("marks/evil-poison")!=1)
{
  tell_object(me,
HIW + "

     我知道了...

     其實您已經先我離開人世了吧...

     我一直在等你對我說這句話...

     或許\這下聯, 讓我為你等了一輩子...

     但沒有關係, 我一直在等你, 真的

           我...一直在等你...靜香\n

" + HIY + "老人對你說道 : 年輕人, 感謝你為我所作的一切
                     我就把當初前教主所創的秘招教你吧...\n" + NOR);

write(HIC + "老人拿出一本書, 按照書上所寫的慢慢道來....\n" + NOR);
tell_object(me,"冥蠱蠶心法的使用方法為 - perform poison.evil-poison\n");

me->set("title","※冥蠱˙秘使※夜叉冥王");

me->set("marks/evil-poison",1);
tell_object(users(),
HIR + "西方冥蠱魔教的天空閃起紅光, 
                          看來失落秘術" + HIB + "萬蠱蠶心術" + HIR + "再度重現人間!!!\n" + NOR);

 write("老人說完, 眼角留下淚\滴, 就這樣在眾人面前斷氣了....\n");
ob->die();
return 1;
}
write("老人搖搖頭, 不理不採...\n");
return 1;
}
int do_change(string str)
{
  object me = this_player();
  if(str=="title-one")
  {
  if(!me->query("marks/evil-poison"))
  return notify_fail("你還沒學會此招喔\n");
  if(me->query("family/family_name")!="冥蠱魔教")
  return notify_fail("你已不是魔教中人\n");
me->set("title",
"※冥蠱˙秘使※夜叉冥王");
tell_object(me,"title修改完成\n");
return 1;
}
}

string do_ans()
{
        object me=this_player();
          me->set_temp("can_say",1);
        return("那個總是陰謀害人的鬼地方我不想在待在那了, 我想住這邊, 村長也同意的, 他同意的!他同意的!!!");
        write("老人不在理會你的任何追問, 只是心慌地左顧右盼...\n");
}

string do_ep7()
{
        object me=this_player();
       if(me->query_temp("quest-e")!=6)
        return("你應該不知道吧??");
       me->set_temp("quest-e",7);
        return("你..你怎麼會知道那一位的事情??
                唉, 都怪我太愛自作多情, 落得這種下場
                真是愧\對<老教主>啊..
                事到如今懷念以往已是不可能的事了, 
                真希望在見到那一位一面.....");
                
}

string do_ep8()
{
        object me=this_player();
       if(me->query_temp("quest-e")!=7)
        return("不知道ㄋㄟ???");
        me->set_temp("quest-e",8);
        return("那已經是往事了, 別再提<前任教主>了...");
}

string do_fb3()
{
        object me=this_player();
        if(me->query_temp("findbook")!=2)
        return("伍員可以買乖乖");
        me->set_temp("findbook",3);
        return("你...怎麼會知道我的真名呢......
好吧, 既然如此, 我就把<往事>都告訴你好了....");
}

string do_fb4()
{
        object me=this_player();
        if(me->query_temp("findbook")!=3)
        return("神經病, 我幹麻和你說我過去輝煌的歷史");
        me->set_temp("findbook",4);
        tell_object(me,HIY + "
老人無奈說道 : 
              其實這一切, 都不應該這麼發生的...
              數十年前, 前教主在修練一中新的蠱毒心法,
              當時我和教主及皇柏壬都很專心研究這武功 , 
              教主會把毒蠱的配方交給皇柏壬去調配, 而我則負責
              去紀錄調配方法...
              只是當時我和皇柏壬都看上了前<教主義女>,
              當時我兩一直爭著想要和她在一起, 只是教主比較賞識
              皇柏壬的才幹,因此決定將她許\配給皇柏壬
              無奈她心屬意之人為我, 我倆便決定私下離去...
              但後來教主發現皇柏壬野心勃勃, 並非真心喜歡她
              只是為了想到教主的女婿, 所以教主便私下決定將
              她改嫁於我, 無奈皇柏壬發現教主的決定, 便想說
              一不做二不休, 用蠱物害死了教主, 並且將罪過栽贓於我
              的身上, 只是最後莊靜柔派遣手下發現事實, 
              將皇柏壬關上數年不得放出, 而我被下令放逐冥魔教...
              .....只是現在, 我內心還是牽掛著那一位.......
              自從那件事情後, 她就消失於魔教了...
              如果你見到他, 請和她說 --
                 " + HIW + "  嫦娥應悔偷靈藥 " + NOR + "
              這樣就可以了.....\n");      
        return("知道了吧....");
}

                

