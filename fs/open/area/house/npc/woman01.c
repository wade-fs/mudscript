 inherit NPC;
#include <ansi.h>
string snake_stone();
string pay_money();

void create()
{
        set_name("婁繡憐",({"iv xiu lian","lian"}));
        set("title","副檀間總管");
        set("long",@LONG
曾是名登天界眾神之一的她，因為喜好研究邪靈一族的秘法而被
開除仙班，為此忿忿不平的她，決定到人世間好好大鬧一場；目前，
她正在研究邪靈石方面的問題．
LONG);
        set("age",131);
        set("combat_exp",100);
        set("int",30);
        set("per",1);
        set("gender","女性");
        set("inquiry",([
"研究":"．．．我幹麻告訴你我的研究．．．\n",
"邪靈石":"．．．想知道？拿一個你認為奇怪的石頭來給我．．．\n",
"石頭":"．．．拿給我就對了．．．\n",
"蛇靈石":(:snake_stone:),
"交易":(:pay_money:),
]));
        setup();
}

int accept_object(object me,object obj)
{
        object ob,obje;
        int i;

        ob= this_object();

        if(obj->query("id") == "red stone" )
        {
                message_vision("
$N仔細的把玩著手中的$n，小心翼翼的觸碰著$n～
不時的露出驚訝的神情與懷疑的眼神！
\n",ob,obj);
                message_vision("
$N將注意力轉向$n，望著$n說：這項物品我並不確定她是否為邪靈石之一
，不過她卻被封印著一股奇特的力量，是屬於不祥的一種．
\n",ob,me);
                message_vision("
$N說：我很樂意幫你將這封印給解除，基於我好奇心上；不過需要$n的一
點力量跟某個物品．．．
\n",ob,me);
                message_vision("
$N說：如果$n願意將你的力量用來破解這個封印，就去拿一只紅寶石指戒
來給我．
\n",ob,me);
                ob->set_temp("get-stone",1);
                destruct(obj);
        }
        else if(obj->query("id") == "ruby_ring" && ob->query_temp("get-stone") )
        {
                if( me->query("combat_exp") >= 10000 )
                {
                        message_vision("
$N興奮的說：很好～既然$n都這麼決定，那我就不客氣了！

"+HIG+"$N嘴裡急速的念著某種話語，臉上曝冒青光，眼神極其恐怖～
緩緩高舉雙手，迅速揮了下來～指間射出一道青光，直直射入$n的眉宇之間！
\n"NOR,ob,me);
                        i = random(-1)+5000;
                        tell_object(me,HIR"
(你損失了"+i+"點經驗值。)\n\n"NOR);
                        me->add("combat_exp",-i);
                        message_vision(HIR+"
[碰～]的一聲巨響！$N手中的$n突然粉碎破散，一陣光耀的紅光散佈整個房間！"+NOR+"

$N看了看，眉頭不自覺的深鎖，緩緩的說：這東西很麻煩，抓(catch)的時候要小心一點，
這是會移動的[蛇靈石]。\n",ob,obj);
                        ob->delete_temp("get-stone");
                        obje = new(__DIR__"obj/move-stone");
                        obje->move(environment(ob));
                }
                else if(me->query("combat_exp") < 10000 )
                {
                        message_vision("
$N說：$n的能力不足，無法解開封印．．．。
\n",ob,me);
                        message_vision("
$N手中的$n毀掉了．．．\n",ob,obj);
                }
                destruct(obj);
        }
return 1;
}

string snake_stone()
{
        object ob,me;

        ob = this_object();
        me = this_player();

        if(!ob->query_temp("string"))
                return "．．．\n";

        message_vision("
$N說：[蛇靈石]相傳是由蠱毒所做成的詛咒，在人體內煉製而成的一種邪靈石，我
並不想知道你是怎麼得到她，．．．不過如果你追丟了她，我倒是滿樂意幫你找，
不過，需要一點點代價．．．。

$N不懷好意的笑著。\n",ob);
        return "不要問我什麼代價，如果願意的話，就跟我[交易]吧．．．\n";
}

string pay_money()
{
        object ob,me;
        int i;

        ob = this_object();
        me = this_player();
        i = 50000+random(50000);

        if(!ob->query_temp("string"))
                return "．．．\n";
        if( me->query("bank/coin") < 100000 )
                return "想跟我交易．．先去錢莊存點錢吧。\n";
        me->add("bank/coin",-i);
        message_vision("$N唸了一小段咒語，緩緩的說著：
\n"+ob->query_temp("string")+"\n",ob);
        return "她就在那裡，自己去找吧！\n";
}
