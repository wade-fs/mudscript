//by roger
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
string do_array();
string do_tigi();
string do_sixplan();
string do_koming();
string do_sehan();
string do_hoba();


void create() {
        set_name(HIC"太公望"NOR,({"master wone","wone","scholar"}));
        set("class","scholar");
        set("nickname","$HIW$天下第一軍師$NOR$");
        set("title",HIY"姜子牙"NOR);
        set("long",
"太公望以助周室王朝取得天下之天才軍師, 並且 
自創兵法計謀, 更勝孫子兵法。 
");
        set("inquiry", ([
        "八卦陣"        : (: do_array :),
        "諸葛孔明"        : (: do_koming :),
        "六韜"          : (: do_sixplan :),
        "太極八卦"    : (: do_tigi :),
        "諸葛瞻"      : (: do_sehan :),
        "諸葛邑昭"    : (: do_hoba :),
]));
        set("str",40);
        set("cor",25);
        set("gender","男性");
        set("guild_master",1);
        set("attitude","heroism");
        set("family/family_name","儒門");
        set("max_gin",5000);
        set("max_kee",8000);
        set("max_sen",8000);
        set("max_force",8000);
        set_skill("force",100);
        set("combat_exp",5000000);
        set("functions/movedown/level",100);
        set("functions/finger/level",100);
set("chat_chance_combat", 100);
set("chat_msg_combat",({
(: perform_action("stabber.movedown") :),
(: perform_action("stabber.finger") :),
}));
        set("chat_chance",50);
        set("chat_msg",({
        }));
        setup();
       carry_object("/u/s/sueplan/newplan/obj/pen")->wield();
       add_money("gold",50);
 }
string do_array()
{
        object me=this_player();
        if(me->query_temp("six_ask")==8)
        {
          me->set_temp("six_ask",9);
        return("
          八卦陣是諸葛孔明所創之陣形, 如果要
        闖過去, 並須要了解太極八卦之變化。");
}
else
        return("做人別太八卦, 真是的!!!");
}
string do_koming()
{
        object me=this_player();
          if(me->query_temp("six_ask")==5)
        {
          me->set_temp("six_ask",6);
          return("
          你說孔明嗎??他就是聞名三國時代的大軍
          師呀, 儒門的諸葛神算就是由孔明所寫
          , 不過諸葛神算裡面的東西並沒有我的 
          六韜裡面的計謀高級, 所以諸葛孔明便
          將我的六韜借去, 到沒想到不久之後他
          就病死了, 將書留給他的傳人諸葛瞻。");
        }
        else
        return("孔明??那是瞎密哇哥..可以吃嗎???");
}          
string do_sehan()
{
        object me=this_player();
        if ( me->query_temp("six_ask")==6)
        {
          me->set_temp("six_ask",7);
          return("
          諸葛瞻是諸葛孔明的後人, 也是一個富
          有智謀的人, 不過他卻把六韜給了他最
          小的兒子諸葛邑昭。");
        }
        else
          return("去死啦!!人家的兒子又不是我生的, 哇阿災!!");
}
string do_hoba()
{
        object me=this_player();
        if( me->query_temp("six_ask")==7)
        {
          me->set_temp("six_ask",8);
          return("
          諸葛邑昭是諸葛一門的敗類, 他拿著
          六韜此書危害著世人, 你幫我把書取回
          吧, 諸葛邑昭現在為於八卦陣中!!");
        }
        else
          return("什麼什麼???");
}
string do_sixplan()
{
        object me=this_player();
        if( me->query("family/family_name")=="儒門" && (me->query_temp("six_ask")==4))
        {
          me->set_temp("six_ask",5);
          return("
          六韜是我寫的戰略書籍之一, 不過我把他傳給了諸葛孔明了
          吧。");
        }
        else
        return("六饕??可以吃嗎??。");
}
string do_tigi()
{
        object me=this_player();
        if( me->query_temp("six_ask")==9)
        {
          me->set_temp("six_ask",10);
          return("
          八卦陣有分八種卦象, 走法是由諸葛孔明利用太極可生兩
          儀, 兩儀可生四象, 四象又生八卦的原理所寫成的, 其中
          可能會遇到各種敵手, 其實他就將八卦陣設在此山的西南
          不過我得先試試你的能耐(test 能耐)。
        ");
        }
        else
          return("太極張三丰~~~~ya~~~");
}
int accept_object(object me, object obj)
{
        if( obj->query("id") == "sixgod-plan book" )
        {
if( me->query_temp("ko_houng") == 1 && !me->query("mark/sixgod-plan") && me->query_temp("ko_hace")==1 && me->query_temp("ko_show")== 1 && me->query_temp("ko_kao")==1 && me->query_temp("ko_yea")== 1 && me->query_temp("ko_jone")== 1)
          {
            command("say 既然你奪取六韜奇略有功\, 我便將六韜奇略上記載的計謀
傳授與你吧。");
          }
        me->set("mark/sixgod-plan",1);
        me->set("title","儒尊『六韜奇略』傳人");

          destruct(obj);
        }
        else
        {
        command("kick "+getuid(me));
        command("say 這東西不是你打的吧???");
        }
        return 1;
}
