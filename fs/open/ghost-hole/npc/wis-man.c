#include <ansi.h>
inherit NPC;
string ask_use();
string ask_water();
void create ()
{
        set_name("老人",({"old man","man","old"}) );
        set("gender","男性");
        set("title",YEL + "幽冥界" + NOR);
        set("nickname",HIW + "智慧之長" + NOR);
        set("age",74);
        set("long","他從小身長在幽冥界內, 對於幽冥界的所有事情都十分了解, 如果對幽冥界有任何的疑問
, 都可以向他請教...\n");
        set("inquiry",([
        "幽冥界":"幽冥界大部分的事情都圍繞在死靈骨魔與其兩大駐守冥王",
        "死靈骨魔":"他是掌管著幽冥界的魔神, 對於他的行為, 我們幽冥界的魔物們早就
對他十分的不滿了!!",
        "不滿":"就算是魔物, 也希望有像人間一樣好的待遇啊, 魔物們也是一種生物啊!!", 
        "行為":"除了殘暴不仁之外, 我不知道該怎麼形容他了..",
        "殘暴不仁":"...我不想多做解釋,你不會比一條豬還笨吧...",
        "待遇":"...我不想多做解釋,你不會比一條豬還笨吧...",
        "生死蝶":"他是死靈骨魔最喜害的寵物, 聽說在前幾年不見了,不過...我知道他在
【死】冥王的手上!!",
        "死冥王":"她跟【生】冥王共同掌管冥界的【生】【死】大權!!",
        "冥王":"在兩年前被死靈骨魔打敗, 後歸屬於死靈骨魔的兩大冥王, 現在為死靈骨魔
的左右手, 分別名為生冥王與死冥王!",
        "生冥王":"他跟【死】冥王共同掌管冥界的【生】【死】大權!!",
        "生命之水":(: ask_water :),
        "死蝶":"生死蝶死後, 就是了死蝶, 你可以拿生命之水讓他復活",
        "使用":(: ask_use :),
        "use":(: ask_use :),
        ]));
        set("chat_chance",1);
        set("chat_msg",({
        "老人神情泰然的到處閒晃著, 彷彿在思考著所有幽冥界的事務...\n",
        "老人突然嘆了一口氣...\n",
        "老人神情古怪的說著一些你聽不懂得話, 似乎十分嚴肅!!\n",
        "老人露出安詳的微笑, 顯得十分的輕鬆...\n",
        "老人激動的說著: 對於幽冥界有什麼不懂得就來問我吧, 我早就想幫助人們
對付死靈骨魔了!!\n",
        "老人自言自語像是在提示著什麼:生死蝶會帶引你們找到通往死靈骨魔的所在
地的, 但是...!!\n",
        }));
        setup();
}
string ask_water()
{
object me=this_player();
object mob=this_object();
if(me->query_temp("ghost-hole/wis-man/know-living-water"))
return "我已經將生命之水給你了啊!!\n";
me->set_temp("ghost-hole/wis-man/do_ask_water",1);
return HIY + "你有生命之水嗎??那是用來讓死蝶復活的必要物!!你知道如何使用(use)嗎??" + NOR;
}


string ask_use()
{
object me;
me=this_player();
if(!me->query_temp("ghost-hole/wis-man/do_ask_water"))
return "你在問什麼啊??我聽不懂....\n";
me->set_temp("ghost-hole/gave-water",1);
return "你先把生命之水給我看看!!\n";
}

int accept_object(object me,object ob)
{
object ob2;
me=this_player();
ob2=new("/autoload/mogi/sspill");
if(ob->query("id")!="living-water")
{
message_vision(HIY + "老人以十分不屑的眼光看著$N給的"+ob->query("name")+", 接著舉起右手, 招幻一個黑洞
, 把"+ob->query("name")+"給吸了進去!!\n" + NOR,me);
return 1;
}
if(!me->query_temp("ghost-hole/gave-water") || me->query_temp("ghost-hole/wis-man/know-living-water"))
{
message_vision(HIY + "老人以十分不屑的眼光看著$N給的"+ob->query("name")+",
老人緩緩說道: 你拿這種東西給我做什麼??
接著招喚一個黑洞, 把"+ob->query("name")+"給吸了進去!!\n" + NOR,me);
return 1;
}
else
{
if(!me->query("got_sen_sen_pill"))
{
message_vision(HIY + "老人高興的笑著:沒想到$N會給我如此貴重的東西, 真是太感激$N了!!\n" + NOR,me);
message_vision(HIY + "老人隨即轉過身去, 從其背後的箱子裡面拿出了一些藥丸\n" + NOR,me);
message_vision(HIR + "老人給了$N一些紅色藥丸!!\n" + NOR,me);
message_vision(HIY + "老神笑著說:這些藥丸很好用的, 就當作是你給我生命之水的謝禮吧!!\n" + NOR,me);
ob2->set_amount(5);
ob2->move(me);
me->set("got_sen_sen_pill",1);
}
message_vision(HIY + "老人心滿意足的笑著:原來生命之水是長的如此模樣啊!!
		哈哈!!謝謝你了!!來..生命之水還給你, 
        你必需把這滴生命之水覆蓋\(cover butterfly)在死蝶身上, 這樣死蝶
		就會復活了!!\n" + NOR,me);
message_vision(HIW + "老人把生命之水還給了$N \n" + NOR,me);
me->delete_temp("ghost-hole/gave-water");
me->set_temp("ghost-hole/wis-man/know-living-water",1);
ob->move(me);
return 1;
}
}
