#include <ansi.h>
#include "../../open.h"

#include <ansi.h>
inherit NPC;
inherit SSERVER;

string chat_msg();
string combat_msg();
int pearl()
{
        object ob;
        ob = this_player();
           if(ob->query("ask_god_kee") != 2)
          return notify_fail("我不了解你在說什麼!!!!\n");
        command("say 原來任正晴都跟你說了呀~~念在你曾幫過我!!");
        command("hmm");
        command("say 好吧!!如果要天靈石就拿天邪石來換好了...!");
          ob->set("get_sky_stone",1);
        return 1;
}
string linhwi()
{
        if( !present("lin sword",this_player()) )
                return "你要帶我去見她嗎 ? 可是我怎麼知道你說的是真是假 ? 有何憑證 ?\n";
        command("follow " + this_player()->query("id"));
        return "好 ! 我這就跟你去 !\n";
}
int accept_object( object who , object ob )
{
  object mid;
  if( ob->query("id") == "stone" && ob->query("quest_stone"))
   {
        if(who->query("get_sky_stone")!=1)
     return notify_fail("你給我這東西做什麼呀??\n");
    say("獨孤雲仔細看了看!!說道:這果然是天邪石。\n");
    command("say 好吧!!我就按照約定把天靈石給你吧。\n");
    mid=new("/open/snow/obj/sky_lin_stone");
    mid->move(who);
    return 1;
  }
  if( ob->query("id") == "lin sword" ) {
                command("nod");
                command("say 好 ! 我這就跟你去 !");
                command("follow " + this_player()->query("id"));
                return 1;
        }
  if( ob->query("id") == "poet book" || ob->name() == HIC + "獨孤詩文集"
        +NOR )
        {
        command("say 謝謝你!!");
        command("hmm");
        command("say 為了感謝你的幫助!!我就告訴你二個秘密!!!");
        command("say 一、劉全書及任正晴曾在玄天聖谷中修習更上層的絕學!!!");
        command("say 二、瀧山掌門練有傳說中的仙雲靈氣!!!");
        who->set("ask_god_kee",1);
        who->set("ask_super_fighter",1);
        return 1;
        }
/*      if( who->query("ice-stial") ) {
                command("?");
                return 1;
                        }

        command("say 謝謝你 ! 好 ! 那麼我就傳授你寒冰掌 !");
        who->set("ice-stial",1);

        if( !who->query_skill("snow-martial",1) )
                who->set_skill("snow-martial",1);

        who->set("functions/ice-stial/level",1);
*/
                command("say 你給我這個幹嘛 ?\n");
                return 0;
}
void create()
{
        set_name("獨孤雲",({"dugur"}));
        set("long",@LONG
他是獨孤愁的獨生子﹐單名一個「雲」字﹐
乃是雪蒼派新生代中排行第一的高手﹐其智慧、
武功、人品等皆堪稱一品﹐而其外貌則十分斯文
﹐有著名人雅士一般的氣勢﹐因此在江湖上有著
一個名號叫「全才書生」。
LONG);
        set("attitude", "heroism");
        set("gender","男性");
        set("nickname",HIC + "全才書生" + NOR);
        create_family("雪蒼派",5,"弟子");
        set("age", 20);
        set("str", 20);
        set("cor", 20);
        set("cps", 20);
        set("per", 30);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",30);
        set("max_kee",1000);
        set("kee",1000);

        set_skill("dodge",70);
        set_skill("black-steps",70);
        map_skill("dodge","black-steps");
        set_skill("sword",50);
        set_skill("stabber",50);
        set_skill("unarmed",80);
        set_skill("snow-martial",80);
        map_skill("unarmed","snow-martial");
        set_skill("force",80);
        set_skill("snowforce",100);
        map_skill("force","snowforce");
        set("combat_exp",500000);

        set("chat_chance",40);
        set("chat_msg",({ (: chat_msg :) }));
        set("chat_chance_combat",60);
        set("chat_msg_combat",({ (: combat_msg :) }));
        set("inquiry",([
                "獨孤愁" : "獨孤愁乃是家父﹐已經仙逝多時了 ...\n",
                "仙逝" : "家父是為了鍛練雪蒼派不傳神功\而走火入魔 ... 唉 . ...\n",
                "去老還童術" : "那是一種十分微妙的一種功\夫﹐相傳修練這種功\夫必需練到極限﹐才能夠返老還童﹐據我所知﹐這種功\夫十分難練﹐而且會的人不多。\n",
                "會的人" : "據我所知﹐只有我爹爹有練過這種功\夫但是並沒有練到極限﹐可惜 ...\n",
                "可惜" : "可惜我爹爹已經仙逝了﹐而且也沒有留下什麼秘笈﹐所以這部功\夫也就因此失傳了。\n",
                "秘笈" : "我爹爹去逝後只有留下幾樣家傳寶貝﹐天誅筆、穿龍劍等等﹐並沒有什麼秘笈留下。\n",
                "天誅筆" : "這是我家傳的寶貝之一﹐這隻筆相當神奇﹐不用墨水就能寫字哦。\n",
                "穿龍劍" : "這是我家傳的寶貝﹐能夠削鐵如泥﹐而且如果配上穿龍劍法﹐更是威力無窮。\n",
                "寒冰掌" : "家父生前曾經教過我這部功\夫﹐但是不能外傳他人﹛M果你能幫我找到﹐我就教你寒冰掌。\n",
                "除非" : "雲畢生最大憾事乃是失落了爹爹生前所著的詩文集﹐如果你能幫我找到﹐我就教你寒冰掌。\n",
                "黑仙羅漢" : "此人嘛 ? .. 我略有所聞﹐此中H早在二十年前就威鎮江湖﹐\n      他的武功\不弱﹐但是自從敗在我爹爹手下﹐就消失武林。\n      我想劉掌門應該更清楚他的來歷。\n",
                "劉玲慧" : (: linhwi :),
                "天靈石" : (: pearl :),
                "諸葛臥龍" : "此人複姓諸葛名臥龍﹐具有經天緯地之才﹐又有神鬼莫測的卜卦能力﹐世稱「神算先生」。\n",
                "神算先生" : "此人生平喜愛結交有知識、有智慧的人士﹐與邢賢書為莫逆之交。\n",
           ]));

        setup();
        carry_object(SNOW_OBJ"dragon-sword");
        carry_object(SNOW_OBJ"tenpen");
        carry_object(SNOW_OBJ"blue-cloth")->wear();

}
int get_power(object ob)
{
        int power;
        string skill_type;
        if(!ob) return 1;
        skill_type = ob->query_temp("skill_type");
        if( skill_type == "unarmed" )
                power = ob->query_skill(skill_type);
        else
                power = ob->query_skill(skill_type) * 2;
        power += ob->query_skill("dodge");
        power += ob->query_skill("parry");
        power += ob->query_temp("apply/damage");
        power += ob->query_temp("apply/armor");
        power += ob->query_temp("apply/attack");
        power += ob->query_temp("apply/dodge");
        power += ob->query("force") * ob->query("force_factor") / 100;
        power += ob->query("combat_exp") / 500;
        return power * ( ob->query("kee") / ob->query("max_kee") );
}
string chat_msg()
{
        return "";
}
string combat_msg()
{
        object ob = offensive_target(this_object());
        int my_power,ob_power;
        if( is_killing() && query("kee") < 120 ) {
                command("say 真是欺人太甚了 ! 呀 ～～～～～");
                command("cast sword");
                command("cast pen");
                return "";
        }
        my_power = get_power(this_object());
        ob_power = get_power(this_player());
        if( ob_power > my_power * 3 / 2 ) {
                command("say 閣下武藝精湛﹐獨孤某佩服 !");
                if( !this_player()->query_temp("weapon") &&
                    !this_player()->query_temp("secondary_weapon") ) {
                        command("say 既然如此﹐在下要盡全力了 !");
                        command("wield all");
                        return "";
                }
                return "";
        }
        if( ob_power < my_power / 2 ) {
                if( this_player()->query_temp("weapon") ) {
                        command("say 倚靠兵器為勝﹐非英雄所為也 !");
                        command("unwield sword");
                        command("unwield pen");
                        return "";
                }
        }
        if( random(3) == 0 ) {
                command("say 來吧 ! 經驗我的天誅筆式 !");
                command("unwield sword");
                command("wield pen");
                return "";
        }
        if( random(3) == 0 ) {
                command("say 穿龍劍法 ～～～");
                command("unwield pen");
                command("wield sword");
                return "";
        }
        return "";
}
int accept_fight(object who)
{
        if( !is_fighting() )
        {
                command("say 閣下既然有興趣領教﹐在下自當奉陪。");
                return 1;
        }
        command("say 在下正在與人比試中﹐若要討教﹐就請稍後。");
        return 0;
}
int accept_kill(object who)
{
        if( is_fighting() || is_killing() )
        {
                command("say 倚多為勝非君子所為 !");
                command("say 也罷 ... 怪不得我了 !");
                command("wield all");
                return 1;
        }
        command("say 在下和你有深仇大恨嗎 ?");
        command("wield pen");
        return 1;
}
/* 會讓天道利用bug.練召喚術.拿掉..
void die()
{
        object killer = query_temp("last_damage_from");
        killer->set("quests/kill-dugur",1);
        message_vision(HIB + @LONG
就在千鈞一髮之際﹐突然的竄出一個黑衣人﹐
黑衣人將獨孤雲扛起來背在肩上﹐$n想上前去
阻止﹐而黑衣人逼不得已﹐只好使出極招﹐只
見黑衣人發出雷霆一掌打在$n身上﹐只聽到「
碰」的一聲﹐$n整個人飛了出去﹗
LONG + NOR,
        this_object(),killer);
        killer->set("kee",1);
        killer->set("force",0);
        COMBAT_D->report_status(killer);
        load_object("/open/snow/room/ducu_live3");
        load_object("/open/snow/room/ducu_live1");
        killer->move("/open/snow/room/ducu_live3");
        killer->move("/open/snow/room/ducu_live1");
        message_vision(HIR + "$N吐了一口鮮血﹐似乎受到了極大的內傷了。\n" + NOR,killer);
        message_vision("黑衣人背著獨孤雲一個飛身就消失無蹤了。\n",this_object());
        destruct(this_object());
}
*/
