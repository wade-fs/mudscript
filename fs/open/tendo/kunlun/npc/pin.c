#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string magic1();
string star1();
string star2();
string star3();

void create()
{
	set_name("平催牛",({"pin"}) );
        set("long","一個道貌岸然的"HIW"算命"NOR"先生，到處招搖撞騙，手裡拿著一面招牌上面寫著『鐵口直斷』四個大字。
兩旁還寫著兩行小字--上知"HIW"天文"NOR"，下知地理。\n");
        set("gender","男性");
        set("class","officer");
        set("combat_exp",60000);
        set("attitude","friendly");
        set("age",62);
	set("title","鐵口直斷");
        set("str", 25);
        set("cor", 30);
        set("cps", 30);
        set("per", 30);
        set("spi", 30);
        set("int", 26);
        set("force", 200);
        set("max_force", 1000);
        set("max_mana",200);
        set("max_atman",150);
        set_skill("security",100);
        set("force_factor", 10);

	set("inquiry",([
	"算命" : (:magic1:),
	"天文" : (:star1:),
	"七星" : (:star2:),
	"八星" : (:star3:),
	]));
        set("chat_chance", 30);
        set("chat_msg", ({
        "平催牛惦了惦手上的銀子，臉上露出滿意的笑容^O^\n",
        "平催牛說道: 這位施主我瞧你臉現青氣，恐怕最近諸事不順，要不要算個命啊!\n",     
        "平催牛大聲說道: 來喔來喔..鐵口直斷，不準不要錢。包你有災解災，沒災發財啦。\n",           
        }));
        setup();
	add_money("silver",3);
}

string magic1()
{
 object who=this_player();
 command("say 讓老夫替你算算");
 command("cmd askgod "+who->query("id"));
 return "算一次命三十兩白銀，謝謝惠顧。";
}

string star1()
{
 return NOR"哈哈！！這你就問對人了。看你要問個"HIW"七星，八星"NOR"都沒問題啦。"NOR;
}

string star2()
{
  
  message_vision (HIC"平催牛說道: 這個簡單，依序就是天樞，天璇，天機，天權，天衡，開陽，瑤光這七顆南斗七星嘛。\n",this_object());
  write(HIC"你不禁心想: 哇勒！....南斗七星?....這個人的話靠的住嗎？\n"NOR);
  return "hmm....這種小問題，收你十兩銀子就好";  
}

string star3()
{
 object who=this_player();

 message_vision (HIC"平催牛說道:八星就是七星加太陰啦!!..連這都不懂，小孩子要好好念書知道嗎!\n",who);
 command("pat "+who->query("id"));
 write("你好像有種受騙的感覺....>.<\n\n");
 return "處罰你不認真唸書，收你一兩黃金";
}

int accept_kill (object who)
{
  command ("shout 哇！....強盜啦....殺人了殺人了!!快來人啊....\n");
  command ("flee");
  return 1;
}
