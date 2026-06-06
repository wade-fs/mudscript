inherit NPC;
#include <ansi.h>
string adv_title();
void create()
{
	set_name("傅劍寒的雕像",({"cgy statue","cgy"}));
	set("long","狂想之神。狂想的玩家為了能瞻仰他，紀念他的德行，所以特別建立了此一雕像。\n你可以試著(pray id)也許\有奇妙的效果喔!!\nexp滿一千萬者可以問他關於稱號的事喔");
	set("title",HIR"惡魔城主"NOR);
	set("nickname",HIW"神"HIG"劍"HIC"飛"HIY"龍"NOR);
	set("unit","尊");
	set("age",291);
	set("value",100);
	set("no_get",1);
	set("no_kill",1);
	set("no_fight",1);
	set("no_sac",1);
	set("no_auc",1);
	set("env/can_tell_wiz","YES");
	set("no_reset",1);
	set_weight(500000);
	setup();
	  set("inquiry", ([
            "稱號"  : (:adv_title:),
			]));
}

init()
{
	add_action("do_pray","pray");
}

int do_pray(string arg)
{
	object me=this_player();

	call_out("greeting",2,me,arg);
	message_vision(HIW"一陣光芒籠罩$N"HIW"的全身，光芒過後，已將$N"HIW"的祈禱傳送到大神的耳邊。\n"NOR,me);

	return 1;
}

void greeting(object ob,string arg)
{
	object me;
	me=this_player();
	command("tell "+arg+" "+me->query("name")+"("+me->query("id")+")傳送一份祝福的祈禱給您!!\n ");

}
string adv_title()
{
object me=this_player();
int i,j,k,b,m;
i=random(6);
j=random(3);
k=random(3);
b=random(4);
m=random(3);
		
        if(me->query("combat_exp") < 10000000 )
            {
                if(!me->query_temp("not_enough_exp"))
                {
                 me->set_temp("not_enough_exp",1);
                 return "你的經驗值不夠, 多加磨練後再來找我吧...";
                }else{
                      me->add_temp("not_enough_exp",1);
                      if(me->query_temp("not_enough_exp") == 2){
                        message_vision(CYN"......經驗值不夠，練強點再來找我吧!!\n"NOR,me);
                        return "去去去";}
                      if(me->query_temp("not_enough_exp") == 3){
                        message_vision(CYN"不是告訴過你經驗值不夠了嗎!?去練強點再來啦\n"NOR,me);
                        return "走開啦";}
                      if(me->query_temp("not_enough_exp") == 4){
                        message_vision(CYN"就跟你說你經驗值不夠了，啊你是聽不懂喔!?\n"NOR,me);
                        return "你煩不煩啊你...";}
                      if(me->query_temp("not_enough_exp") == 5){
                        message_vision(CYN"你還來!?我扁你喔\n"NOR,me);
                        return "還不滾!?";}
                      if(me->query_temp("not_enough_exp") == 6)  
                      {
                      message("system",HIY"傅劍寒"HIW"大聲說道:"HIM"不要臉的"HIY+this_player()->name()+HIM"沒事妄想更動頭銜，以後就叫他"HIG"沽名釣譽"HIR"大白痴"HIM"吧\n"NOR,users());
                      me->set("title",HIG"沽名釣譽"HIR"大白痴"NOR);
                      return "哈哈哈!!";
                      }
                      if(me->query_temp("not_enough_exp") > 6) return "哈哈哈，活該"; 
                     }
            }
        if(me->query("class")=="fighter")
		{
		if(i==0){
                me->set("title",HIY"ζ"HIG"傲世天下"HIY"ζ"HIM"紫燄"HIY"．"HIC"武神"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIY"ζ"HIG"傲世天下"HIY"ζ"HIM"紫燄"HIY"．"HIC"武神"NOR"稱號\n"NOR,users());
                } 
		else if(i==1){
                me->set("title",HIG"拳掌"HIY"雙霸"HIW"～"HIC"笑蒼天"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIG"拳掌"HIY"雙霸"HIW"～"HIC"笑蒼天"NOR"稱號\n"NOR,users());;
                }
		else if(i==2){
                me->set("title",HIY"傲世三俠"HIB"《"HIG"恨 無 敵"HIB"》"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIY"傲世三俠"HIB"《"HIG"恨 無 敵"HIB"》"NOR"稱號\n"NOR,users());;
                }
		else if(i==3){
                me->set("title",HIY"傲世三俠"HIB"《"HIM"龍 無 情"HIB"》"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIY"傲世三俠"HIB"《"HIM"龍 無 情"HIB"》"NOR"稱號\n"NOR,users());;
                }
		else if(i==4){
                me->set("title",HIY"傲世三俠"HIB"《"HIC"星 無 蹤"HIB"》"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIY"傲世三俠"HIB"《"HIC"星 無 蹤"HIB"》"NOR"稱號\n"NOR,users());;
                }
		else{
		me->set("title",HIB"ζ"HIC"武道"HIY"˙"HIR"奇俠"HIB"ζ"NOR) ;
				message("system",HIG"陸清風朗聲說道:恭喜"HIY+this_player()->name()+HIM"成為"HIB"ζ"HIC"武道"HIY"˙"HIR"奇俠"HIB"ζ"NOR"稱號\n"NOR,users());
                }
		return "恭喜妳獲得新的稱號";
		}
		if(me->query("class")=="prayer")
		{
		if(j==0){
                me->set("title",HIR"ξ"HIM"末日"HIW"聖"HIY"光"HIG"使者"HIR"ξ"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIR"ξ"HIM"末日"HIW"聖"HIY"光"HIG"使者"HIR"ξ"NOR"稱號\n"NOR,users());
                } 
		else if(j==1){
                me->set("title",HIY"ζ"HIM"滅"HIB"世"HIC"天"HIR"火"HIW"武神"HIY"ζ"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIY"ζ"HIM"滅"HIB"世"HIC"天"HIR"火"HIW"武神"HIY"ζ"NOR"稱號\n"NOR,users());
                }
		else {
		        me->set("title",HIB"∮"HIW"帝魂"HIB"∮"HIM"聖"HIR"火"HIC"天"HIY"皇"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIB"∮"HIW"帝魂"HIB"∮"HIM"聖"HIR"火"HIC"天"HIY"皇"NOR"稱號\n"NOR,users());
                }
		return "恭喜妳獲得新的稱號";
		}
		if(me->query("class")=="blademan")
		{
		if(b==0){
                me->set("title",HIB"ξ"HIM"魔光初現"HIB"ξ"HIR"赤燄"HIW"˙"HIC"刀尊"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIB"ξ"HIM"魔光初現"HIB"ξ"HIR"赤燄"HIW"˙"HIC"刀尊"NOR"稱號\n"NOR,users());
                } 
		else if(b==1){
                me->set("title",HIR"刀魂"HIG"∮"HIY"怒"HIB"˙"HIM"斬"HIB"˙"HIC"殺"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIR"刀魂"HIG"∮"HIY"怒"HIB"˙"HIM"斬"HIB"˙"HIC"殺"NOR"稱號\n"NOR,users());
                }else if(b==2){
                if(me->query("family/family_name") == "金刀門")
                {
                me->set("title",HIW"◣"HIC"一刀傾城"HIW"◥"HIY"霸"HIR"烈"CYN"刀"HIB"聖"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIW"◣"HIC"一刀傾城"HIW"◥"HIY"霸"HIR"烈"CYN"刀"HIB"聖"NOR"稱號\n"NOR,users());
                }else{
                me->set("title",HIW"◤"HIR"邪魔轉生"HIW"◢"HIG"妖"HIM"-"HIB"刀"HIM"-"HIY"皇"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIW"◤"HIR"邪魔轉生"HIW"◢"HIG"妖"HIM"-"HIB"刀"HIM"-"HIY"皇"NOR"稱號\n"NOR,users());
                     }
                }
		else {
		        me->set("title",HIM"《"HIC"一代刀神"HIM"》"HIY"怒殺千里"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIM"《"HIC"一代刀神"HIM"》"HIY"怒殺千里"NOR"稱號\n"NOR,users());
                }
		me->set("get-new-title",1);
		return "恭喜妳獲得新的稱號";
		}
		if(me->query("class")=="killer")
		{
		if(k==0){
                me->set("title",HIB"黑牙聯"HIR"首"HIY"席"HIG"殺"HIC"手"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIB"黑牙聯"HIR"首"HIY"席"HIG"殺"HIC"手"NOR"稱號\n"NOR,users());
                } 
		else if(k==1){
                me->set("title",HIW"ψ"HIM"霸魂"HIW"、"HIC"闇影"HIW"ψ"HIR"極"HIG"道"HIY"殺"HIB"神"NOR) ;
message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIW"ψ"HIM"霸魂"HIW"、"HIC"闇影"HIW"ψ"HIR"極"HIG"道"HIY"殺"HIB"神"NOR"稱號\n"NOR,users());
                }
		else {
                me->set("title",HIR"賞"HIY"金"HIG"獵"HIC"人"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIR"賞"HIY"金"HIG"獵"HIC"人"NOR"稱號\n"NOR,users());
                }
		me->set("get-new-title",1);
		return "恭喜妳獲得新的稱號";
		}

  if(!me->query("get-new-title")&&me->query("class")=="swordsman")


     {
  if(k==0){
    me->set("title",HIB"Υ"HIM"神劍修羅"HIB"Υ"NOR);
    message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予劍俠"HIB"Υ"HIM"神劍修羅"HIB"Υ"NOR"稱號\n"NOR,users());
          }
  else if(k==1){
    me->set("title",HIR"Ξ"HIY"靈"HIB"幻"HIM"天"HIB"劍"HIR"Ξ"NOR) ;
    message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIR"Ξ"HIY"靈"HIB"幻"HIM"天"HIB"劍"HIR"Ξ"NOR"稱號\n"NOR,users());

          }
  else {
    me->set("title",HIM"《"HIC"絕世劍俠"HIM"》"HIY"芎天蒼宇"NOR) ;
    message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIM"《"HIC"絕世劍俠"HIM"》"HIY"芎天蒼宇"NOR"稱號\n"NOR,users());
       }
       me->set("get-new-title",1);
       return "恭喜妳獲得新的稱號";
     }
     if(me->query("class")=="marksman")
		{
		if(m==0){
                me->set("title",HIR"￡"HIY"絕世"HIM"‧"HIC"箭魂"HIR"￡"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIR"￡"HIY"絕世"HIM"‧"HIC"箭魂"HIR"￡"NOR"稱號\n"NOR,users());
                } 
		else if(m==1){
                me->set("title",HIB"ζ"HIR"箭之痕"HIY"‧"HIC"冰沁"HIM"箭癡"HIB"ζ"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIB"ζ"HIR"箭之痕"HIY"‧"HIC"冰沁"HIM"箭癡"HIB"ζ"NOR"稱號\n"NOR,users());
                }
		else {
		        me->set("title",HIC"◤"HIR"箭傲天下"HIW"‧"HIM"狂箭皇"HIC"◢"NOR) ;
				message("system",HIY"傅劍寒"HIW"大聲說道:"HIY+this_player()->name()+HIM"苦練有成特賜予"HIC"◤"HIR"箭傲天下"HIW"‧"HIM"狂箭皇"HIC"◢"NOR"稱號\n"NOR,users());
                }
		return "恭喜妳獲得新的稱號";
		}
}
