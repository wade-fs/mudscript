// 全新改版 by swy
// 再次整合審查 npc 會暴強問題 by swy
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include <login.h>
inherit F_DBASE;
inherit SSERVER;
// skills 裡的 force 值
mapping force_div = ([
  "fighter"   :500,
  "bandit"    :400,
  "swordsman" :400,
  "blademan"  :400,
  "scholar"   :300,
  "bonze"     :300,
  "officer"   :300,
  "prayer"    :300,
  "beggar"    :300,
  "marksman"  :300,
  "dancer"    :200,
  "poisoner"  :100,
  "killer"    :100,
  "taoist"    :100,
  "doctor"    :100,
]);
// skills 裡的 damage 值
mapping damage_div = ([
  "fighter"   :500,
  "bandit"    :400,
  "swordsman" :400,
  "blademan"  :400,
  "scholar"   :300,
  "bonze"     :300,
  "officer"   :300,
  "prayer"    :300,
  "beggar"    :300,
  "marksman"  :300,
  "dancer"    :200,
  "poisoner"  :100,
  "killer"    :100,
  "taoist"    :100,
  "doctor"    :100,
]);
// class 基本命中率
mapping hurt_div = ([
  "fighter"   :500,
  "bandit"    :600,
  "swordsman" :600,
  "blademan"  :600,
  "scholar"   :700,
  "bonze"     :700,
  "officer"   :700,
  "prayer"    :700,
  "beggar"    :700,
  "killer"    :700,
  "marksman"  :700,
  "dancer"    :800,
  "poisoner"  :800,
  "taoist"    :800,
  "doctor"    :800,
]);
// class 招架調整值
mapping parry_div = ([
  "dancer"    :       9,
  "poisoner"  :       9,
  "doctor"    :       8,
  "taoist"    :       8,
  "killer"    :       8,
  "marksman"  :       7,
  "scholar"   :       7,
  "bandit"    :       7,
  "prayer"    :       6,
  "officer"   :       6,
  "fighter"   :       6,
  "bonze"     :       5,
  "beggar"    :       5,
  "blademan"  :       4,
  "swordsman" :       4,
]);

string *guard_msg = ({
  CYN + "$N注視著$n的行動﹐企圖尋找機會出手。\n" + NOR,
  CYN + "$N正盯著$n的一舉一動﹐隨時準備發動攻勢。\n" + NOR,
  CYN + "$N緩緩地移動腳步﹐想要找出$n的破綻。\n" + NOR,
  CYN + "$N目不轉睛地盯著$n的動作﹐尋找進攻的最佳時機。\n" + NOR,
  CYN + "$N不停的在$n身旁遊移著﹐專心的尋找$n的破綻。\n" + NOR,
  CYN + "$N慢慢地移動著腳步﹐伺機出手。\n" + NOR,
  CYN + "$N眼觀四路﹐耳聽八方﹐集中精神與$n纏鬥著。\n" + NOR,
  CYN + "$N步步為營﹐雙眼直視著$n﹐想找出$n的防守漏洞。\n" + NOR,
});

string *catch_hunt_msg = ({
  YEL + "$N和$n仇人相見分外眼紅﹐立刻打了起來﹗\n" + NOR,
  YEL + "$N對著$n大喝﹕「可惡﹐又是你﹗」\n" + NOR,
  YEL + "$N和$n一碰面﹐二話不說就打了起來﹗\n" + NOR,
  YEL + "$N一見到$n﹐冷冷的道﹕「我倆還真是有緣呀﹗去死吧﹗」\n" + NOR,
  YEL + "$N一眼瞥見$n﹐「哼」的一聲衝了過來﹗\n" + NOR,
  YEL + "$N一見到$n﹐愣了一愣﹐大叫﹕「我宰了你﹗」\n" + NOR,
  YEL + "$N對著$n冷冷的哼了一聲﹐想致$n於死地﹗\n" + NOR,
  YEL + "$N與$n擦肩而過﹐立刻轉過身來﹐大叫﹕「小王八蛋哪裡跑﹗」\n" + NOR,
});

int death_effect(object victim);
string dodge_skill, parry_skill,skill_map,class1,class2,class3,my_skill_message2,k_class;
string rstrone,rstrtwo;
int ap, dp, op, pp,fap,fdp, damage, damage_bonus, i,my_skill=0,choose_skill;
int wounded=0,ppp,divv,div1_2,div1,div2,c1,c2,cmexp,my_skill_power=0,power_dam;
int bssone=0;
int pod;
int dodge_ratio;

void create()
{
    seteuid(getuid());
    set("name", "死神");
    set("id", "deadgod");
}

string damage_msg(int damage, string type)
{
    
    string str;
    object me = this_player();
    object victim;
    if(!me) me=previous_object();
    if(!me) return "";
    victim=offensive_target(me);
    if(!victim) return "";
    if( damage == 0 )
	return "結果沒有造成任何傷害。\n";
    //這部份會照成玩家的因擾,所以我先Disable by Chan 2002/08/11
    /*
    if( damage > victim->query("max_kee")*2 ) {
	if( !userp(victim) )
	    victim->set( "corpse_gone", 1 );
	str = HIR + "結果聽見「轟」地一聲驚天巨響, 極度驚恐的$n瞬間化成齎粉, 灰飛湮滅。" + NOR;
	if( wizardp(me) )
	    str += "(" + damage + ")";
	return str + "\n";
    }
    */
    if( wizardp(me) || wizardp(victim) )
	return "造成 " + HIR + damage + NOR + " 點" + type + "。\n";
    switch( type ) {
    case "斲傷":
    case "割傷":
	if( damage < 100 ) return "結果只是輕輕地劃破$p的皮肉。\n";
	else if( damage < 300 ) return "結果在$p$l劃出一道細長的血痕。\n";
	else if( damage < 500 ) return "結果「嗤」地一聲劃出一道傷口﹗\n";
	else if( damage < 700 ) return "結果「嗤」地一聲劃出一道血淋淋的傷口﹗\n";
	else if( damage < 900 ) return "結果「嗤」地一聲劃出一道又長又深的傷口﹐濺得$N滿臉鮮血﹗\n";
	else return "結果只聽見$n一聲慘嚎﹐$w已在$p$l劃出一道深及見骨的可怕傷口﹗﹗\n";
	break;
    case "刺傷":
	if( damage < 100 ) return "結果只是輕輕地刺破$p的皮肉。\n";
	else if( damage < 300 ) return "結果在$p$l刺出一個創口。\n";
	else if( damage < 500 ) return "結果「噗」地一聲刺入了$n$l寸許\﹗\n";
	else if( damage < 700 ) return "結果「噗」地一聲刺進$n的$l﹐使$p不由自主地退了幾步﹗\n";
	else if( damage < 900 ) return "結果「噗嗤」地一聲﹐$w已在$p$l刺出一個血肉糢糊的血窟窿﹗\n";
	else return "結果只聽見$n一聲慘嚎﹐$w已在$p的$l對穿而出﹐鮮血濺得滿地﹗﹗\n";
	break;
    case "瘀傷":
	if( damage < 500 ) return "結果只是輕輕地碰到﹐比拍蒼蠅稍微重了點。\n";
	else if( damage < 1000 ) return "結果在$p的$l造成一處瘀青。\n";
	else if( damage < 1500 ) return "結果一擊命中﹐$n的$l登時腫了一塊老高﹗\n";
	else if( damage < 2000 ) return "結果一擊命中﹐$n悶哼了一聲顯然吃了不小的虧﹗\n";
	else if( damage < 2500 ) return "結果「砰」地一聲﹐$n退了兩步﹗\n";
	else if( damage < 3500 ) return "結果這一下「砰」地一聲打得$n連退了好幾步﹐差一點摔倒﹗\n";
	else if( damage < 4500 ) return "結果重重地擊中﹐$n「哇」地一聲吐出一口鮮血﹗\n";
	else if( damage < 5500 ) return "結果這毀天滅地「轟」地一擊使得$n血流滿地﹗\n";
	else return "結果只聽見「砰」地一聲巨響﹐$n像一捆稻草般飛了出去﹗﹗\n";
	break;
    case "鞭傷":
	if( damage < 100 ) return "結果只是從$l表面輕輕擦過。\n";
	else if( damage < 300 ) return "結果啪的一聲在$p$l打了一條殷紅的鞭痕。\n";
	else if( damage < 500 ) return "結果刷的一聲在$p$l抽了一道又長又深的可怖血痕！\n";
	else if( damage < 700 ) return "結果$n一聲哀嚎，身上已多了條深及見骨的可怕傷口！\n";
	else if( damage < 900 ) return "結果只聽見$n一聲慘叫，$n$l已被抽的皮開肉綻,鮮血直流！\n";
	else return "結果一鞭命中,只聽見咯啦一聲,，$n哀嚎倒地$l筋斷骨裂,鮮血狂湧不止﹗﹗\n";
	break;
    default:
	if( !type ) type = "傷害";
	if( damage < 100 ) str =  "結果只是勉強造成一處輕微";
	else if( damage < 300 ) str = "結果造成輕微的";
	else if( damage < 500 ) str = "結果造成一處";
	else if( damage < 700 ) str = "結果造成一處嚴重";
	else if( damage < 900 ) str = "結果造成頗為嚴重的";
	else if( damage < 1100 ) str = "結果造成相當嚴重的";
	else if( damage < 1300 ) str = "結果造成十分嚴重的";
	else if( damage < 1500 ) str = "結果造成極其嚴重的";
	else str =  "結果造成非常可怕的嚴重";
	return str + type + "﹗\n";
    }
}

string eff_status_msg(int ratio)
{
    if( ratio==100 ) return HIW + "看起來氣血充盈﹐並沒有受傷。" + NOR;
    if( ratio > 95 ) return HIG + "似乎受了點輕傷﹐不過光從外表看不大出來。" + NOR;
    if( ratio > 90 ) return HIG + "看起來可能受了點輕傷。" + NOR;
    if( ratio > 80 ) return GRN + "受了幾處傷﹐不過似乎並不礙事。" + NOR;
    if( ratio > 60 ) return HIY + "受傷不輕﹐看起來狀況並不太好。" + NOR;
    if( ratio > 40 ) return YEL + "氣息粗重﹐動作開始散亂﹐看來所受的傷著實不輕。" + NOR;
    if( ratio > 30 ) return HIR + "已經傷痕累累﹐正在勉力支撐著不倒下去。" + NOR;
    if( ratio > 20 ) return HIR + "受了相當重的傷﹐只怕會有生命危險。" + NOR;
    if( ratio > 10 ) return RED + "傷重之下已經難以支撐﹐眼看就要倒在地上。" + NOR;
    if( ratio > 5  ) return RED + "受傷過重﹐已經奄奄一息﹐命在旦夕了。" + NOR;
    return                  RED + "受傷過重﹐已經有如風中殘燭﹐隨時都可能斷氣。" + NOR;
}

string status_msg(int ratio)
{
    if( ratio==100 ) return HIW + "看起來充滿活力﹐一點也不累。" + NOR;
    if( ratio > 95 ) return HIG + "似乎有些疲憊﹐但是仍然十分有活力。" + NOR;
    if( ratio > 90 ) return HIG + "看起來可能有些累了。" + NOR;
    if( ratio > 80 ) return GRN + "動作似乎開始有點不太靈光﹐但是仍然有條不紊。" + NOR;
    if( ratio > 60 ) return HIY + "氣喘噓噓﹐看起來狀況並不太好。" + NOR;
    if( ratio > 40 ) return YEL + "似乎十分疲憊﹐看來需要好好休息了。" + NOR;
    if( ratio > 30 ) return HIR + "已經一副頭重腳輕的模樣﹐正在勉力支撐著不倒下去。" + NOR;
    if( ratio > 20 ) return HIR + "看起來已經力不從心了。" + NOR;
    if( ratio > 10 ) return RED + "搖頭晃腦、歪歪斜斜地站都站不穩﹐眼看就要倒在地上。" + NOR;
    return                  RED + "已經陷入半昏迷狀態﹐隨時都可能摔倒暈去。" + NOR;
}

varargs void report_status(object ob, int effective)
{
    if(!ob) return ;
    if(ob->query("max_kee") <1) return ;
    if( effective )
	message_vision( "( $N" + eff_status_msg(
	    (int)ob->query("eff_kee") * 100 / (int)ob->query("max_kee") )
	  + " )\n", ob);
    else
	message_vision( "( $N" + status_msg(
	    (int)ob->query("kee") * 100 / (int)ob->query("max_kee") )
	  + " )\n", ob);
}

// by ACKY
varargs void report_kee( object me )
{
    tell_object( me, sprintf( "\t[ %s精力: %d" + NOR + " %s氣血: %d" + NOR + " %s神瞑: %d" + NOR + " ]\n",
	STATUS("gin"), me->query("gin"), STATUS("kee"), me->query("kee"), STATUS("sen"), me->query("sen") ) );
}

varargs int skill_power(object ob, string skill, int usage)
{
    int level, power, app1, app2,mpower;
    if(!ob) return 0;
    if( !living(ob) ) return 0;
    level = ob->query_skill(skill);
    switch(usage) {
    case SKILL_USAGE_ATTACK:
	app1 = ob->query_temp("apply/attack");
	if(userp(ob)) {
	    if(app1>100) app1=100;
	} else { if(app1>80) app1=80; }
	level += app1;
	break;
    case SKILL_USAGE_DEFENSE:
	app1 = ob->query_temp("apply/defense");
	if(userp(ob)) {
	    if(app1>100) app1=100;
	} else { if(app1>80) app1=80; }
	app2 = ob->query_temp("apply/armor");
	if(userp(ob)) {
	    if(app2>100) app2=100;
	} else { if(app2>80) app2=80; }
	level += (app1+app2);
	break;
    case SKILL_USAGE_OTHER:
	app1 = ob->query_temp("apply/dodge");
	if(userp(ob)) {
	    if(app1>100) app1=100;
	} else { if(app1>80) app1=80; }
	app2 = ob->query_temp("apply/parry");
	if(userp(ob)) {
	    if(app2>100) app2=100;
	} else { if(app2>80) app2=80; }
	level += (app1+app2);
	break;
    }
    if( !level ) return (int)ob->query("combat_exp")/2000;
    //mpower,這個就是temp的了,doctor and wiz專用,by bss
    if(ob->query_temp("mpower")==1
      && (ob->query("class")=="doctor" || wizardp(ob))) {
	power = (level*level)*2; }
    //mpower,是set的喔,不是temp的,npc and wiz專用, by swy and bss
    else if(wizardp(ob) || !userp(ob)) {
	mpower=ob->query("mpower")+1; 
	if(!mpower) mpower=1;
	power = (level*level)*mpower; 
    }
    else {
	mpower=1;
	power = (level*level)*mpower;        
    }
    return power + (int)ob->query("combat_exp")/2000;
}

varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
    object *t;
    mapping my,your, action;
    string limb, *limbs, result, attack_skill,arrow_path,my_skill_message,skill_number,ID,file;
    rstrone="";
    rstrtwo="";
    my = me->query_entire_dbase();
    your = victim->query_entire_dbase();
    // ================================================================
    // (1) 找出打架訊息, 根據武器種類而定
    // 修正 by Chan為了讓玩家使用出自己的招式在這裏修正!!!!目前只有設計出攻擊的招式!!!
    // 主要是分成二部份
    if( attack_type == TYPE_THIRD_HAND) {
      action = me->query("third_actions");
    } else if( attack_type == TYPE_SECOND_HAND) 
    {
      action = me->query("secondary_actions");
    } else {
    action = me->query("actions");
    }
    
    if( !mapp(action) ) {
	me->reset_action();
	action = me->query("actions");
    }
    if( !mapp(action) ) {
	CHANNEL_D->do_channel( this_object(), "sys",
	  sprintf("%s(%s): bad action = %O",
	    me->name(1), me->query("id"), me->query("actions", 1)));
	return 0;
    }
    choose_skill = -1;
    // 自創招式部分  by swy
    if(me->query("env/my_skill") && (sizeof(me->query("hero")) > 2) && (random(100) < 30))
    {
	choose_skill=sizeof(me->query("hero"));
	if(me->query("combat_exp") > 8000000 && random(100) < 6)
	{
	    choose_skill=choose_skill-1;
	    for(i=1;i<choose_skill;i++)
	    {
		skill_number=sprintf("%d",i);
		my_skill_message2=me->query("hero/action"+skill_number);
		my_skill_message=my_skill_message+"\n"+my_skill_message2+"\n";
		my_skill_message=my_skill_message+HIW+"$N心神進入劍心通明的境界,連綿不絕般使出自創之招式"+NOR;
	    }
	}
	else{
	    choose_skill=choose_skill-1;
	    choose_skill=random(choose_skill); //取亂數的方式來找出適合的!!!!
	    if(!choose_skill) choose_skill=1;
	    skill_number=sprintf("%d",choose_skill);
	    if(!me->query("hero/action"+skill_number))
		my_skill_message="$N招式還沒有設計好!!你招式有問題有問題!!!!\n";
	    else
		my_skill_message=me->query("hero/action"+skill_number);
	}
	result = "\n" + my_skill_message + "\n";
	my_skill_power=choose_skill-1;
    }
    else {
	result = "\n" + action["action"] + "\n";
    }
    // 計算出攻方攻擊力,防方防禦力,防方額外防禦力 by swy
    if( objectp(weapon) )  {
      attack_skill = weapon->query("skill_type");
        if(attack_skill == "archery")
        {
          if(weapon->query("arrow/amount") < 1)
            attack_skill = "staff";
        }
    }
    else attack_skill = "unarmed";
    limbs = victim->query("limbs");
      if(sizeof(limbs))
    limb = limbs[random(sizeof(limbs))];
      else
        limb= "奇怪的地方";
    ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);   // 攻方攻擊力
    if( !ap ) ap = 1;
    dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);   // 防方防禦力
    if( !dp ) dp = 1;
    op = skill_power(victim, "dodge", SKILL_USAGE_OTHER);     // 防方額外防禦力
    if( !op ) op = 1;
    if( objectp(weapon) )  {
	damage = (int) me->query_temp("apply/damage");
	if( damage > 500 ) damage = 500;
    } else damage = 0;
    // 以 skill 作為主要的傷害力 by swy
    skill_map = me->query_skill_mapped(attack_skill);
    me->set_temp("level_1", me->query_skill(attack_skill, 1));
    me->set_temp("level_2", me->query_skill(skill_map, 1));
    me->set_temp("level_3", me->query_skill("force", 1));
    // npc 傷害力會比 ppl 小一些 by swy        
    damage += (int)(me->query_temp("level_1")*2+me->query_temp("level_3"));
    if(userp(me)) {
	if( me->query_temp("level_2") >= 1 )
	    damage += me->query_temp("level_2")*3;
	else damage = damage; } else {
	if( me->query_temp("level_2") >= 1 )
	    damage += me->query_temp("level_2")*2;
	else damage = damage; }
    me->delete_temp("level_1");
    me->delete_temp("level_2");
    me->delete_temp("level_3");
    // 額外傷害力先加上臂力影響 by swy
    // 加上 skills 裡 damage 的值
    // 我把 skills 裡 damage 設定在 combatd.c 裡面
    // 一方面我可以不用改 skills 的 damage
    // 另一方面可以防止有人動檔案 by swy
    // 沒有 class npc 的 skills damage 以最高 700 來計算 by swy
    // 沒有 class ppl 的 skills damage 以最高 50 來計算 by swy
    damage_bonus = my["str"];
    class1=my["class"];
    divv=damage_div[class1];
    if(!divv && !userp(me) && action["damage"]) {
	divv=action["damage"];
	if(!divv) divv=100;
	if(divv>700) divv=700; }
    else if(!divv && !userp(me)) {
	divv=100; } else {
	if(!divv && userp(me)) divv=50;
    }

    damage += divv;
    // 敵人 busy 時防禦力降 20% by swy
    if( victim->is_busy() ) dp=dp*4/5;
    
    //加入測試，action中設定dodge對於命中率的影響
    //dodge的範圍是-100~100，設定-100的話就是這招必中無疑，躲都躲不掉
    //0的話就是此招中與不中完全由之前的公式決定，
    //正值則會增加敵人多躲掉這招的可能
    //方法先用類似上面自創招時dp的計算來決定 by bss
    //因為是測試，所以指定對像
    if(me->query("class")=="lancer" || wizardp(me))
	if(action["dodge"]){
	    dodge_ratio=action["dodge"];
	    if(dodge_ratio >0){
		while(dodge_ratio >100)//設定超過100的話就是設定錯誤
		    dodge_ratio/=100; //所以先除100再說
		dp=dp+(dp*dodge_ratio)/100;
	    }
	    else{
		while(dodge_ratio < -100)//設定超過了-100就是設定錯誤
		    dodge_ratio/=100; //所以先除100再說
		dodge_ratio=100-(100+dodge_ratio);
		dp=(dp*dodge_ratio)/100; //提高ratio的比率
		if(!dp) dp=1; //如果dodge設定是-100的話，給dp一個基本值1
	    }
	}
    // 命中率應該由 class 命中率 + 實戰經驗來判定 by swy
    // 如果攻擊方是 npc 又沒有 class 設定為 500 by swy
    // 如果防禦方是 npc 又沒有 class 設定為 500 by swy
    class2=my["class"];
    div1=hurt_div[class2];
    if(userp(me) && !div1) div1=400;
    if(!userp(me) && !div1) div1=500;
    c1=(int)my["combat_exp"];
    c2=(int)your["combat_exp"];
    if(c1-c2<0) { div2=0; }
    else if(c1-c2>=4000000) { div2=400; }
    else if(c1-c2>=3000000) { div2=300; }
    else if(c1-c2>=2000000) { div2=200; }
    else if(c1-c2>=1000000) { div2=100; }
    else { div2=50; }
    div1_2=div1+div2;
    if(div1_2>900) div1_2=900;
    // 射手系統 part 1 by swy
    // 射中左眼或右眼命中率減半  雙眼都射重失明  命中率 = 0
    // 當然合理    也是 doctor 才能醫治
    if(me->query_temp("over/r-eyes")==1&&me->query_temp("over/l-eyes")==1) {
	div1_2=100;
	tell_object(me,HIY + "你雙眼失明毫無中命率可言!\n" + NOR);
    } else if(me->query_temp("over/r-eyes")==1||me->query_temp("over/l-eyes")==1) {
	div1_2 /= 2;
	tell_object(me,HIG + "你眼睛受傷命中率驟減一半!\n" + NOR);
    }

    if(div1_2<random(1000)) {
	dodge_skill = victim->query_skill_mapped("dodge");
	if( !dodge_skill ) dodge_skill = "dodge";
    /*
	// 假設有2個參數就要傳2個值進去
	if(filter_array(functions(load_object(SKILL_D(dodge_skill)),1)
	    ,(:sizeof(regexp($1,"^query_dodge_msg$")):))[0][1] != 1) 
	    result = SKILL_D(dodge_skill)->query_dodge_msg(limb,victim);
	else
	if (SKILL_D(dodge_skill)->query_dodge_msg(limb))
	    result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
      */
  {
    string dodge_string = SKILL_D(dodge_skill)->query_dodge_msg(limb,victim,me);
    if(functionp(dodge_string)) dodge_string = evaluate(me,victim);
    result += dodge_string;
  }
	if( dp < ap && (!userp(victim) || !userp(me))
	  && random(your["gin"]*100/(your["max_gin"]+1) + your["int"]) > 50 ) {
	    your["combat_exp"] += 1;
	    victim->improve_skill("dodge", 1);
	}
	damage = RESULT_DODGE;
    }
    else {
	// 是否被招架開 by swy
	if( victim->query_temp("weapon") ) {
	    pp = skill_power(victim, "parry", SKILL_USAGE_OTHER);
	    pp = pp * 1.2;
	}
	else {
	    pp = skill_power(victim, "parry", SKILL_USAGE_OTHER);
	}
	class1=your["class"];
	if(!class1) divv=10;
	else
	    divv=parry_div[class1];
	if(!divv) divv=10;

	if( victim->is_busy() )
	    pp=pp/divv;
	else {
	    ppp = (pp*10)/divv;
	    pp=(pp+ppp)/2;
	}
	if( pp < 1 || !pp ) pp = 1;
	// 增加parry message by Roger && Chan
	// 說明:只有當我方手中有兵器或敵我都沒兵器時才能招架
	// 換句話說如果對方有兵器自己沒拿就無法招架了
	// 有武器時的parry_msg，但武者不管手中有無武器parry_msg 都一樣 By Roger
	
	if( random(ap + pp) < pp ) {
	    
	    if( dp < ap && (!userp(victim) || !userp(me))
	      && random(your["gin"]*100/your["max_gin"] +
		your["int"]) > 50 ) {
		your["combat_exp"] += 1;
		victim->improve_skill("parry", 1);
	    }
	    if( victim->query_temp("weapon") || your["class"]=="fighter" )
	    {
        parry_skill = victim->query_skill_mapped("parry");
		if( !parry_skill )
		    result += SKILL_D("parry")->query_parry_msg(weapon);
		// 假如有2個參數，就要傳2個參數進去
		else /*if(sizeof(filter_array(functions(load_object(SKILL_D(parry_skill)),1)
		      ,(:sizeof(regexp($1,"^query_parry_msg$")):))) &&
		  filter_array(functions(load_object(SKILL_D(parry_skill)),1)
		    ,(:sizeof(regexp($1,"^query_parry_msg$")):))[0][1] == 2) 
		    
		    result += SKILL_D(parry_skill)->query_parry_msg(limb,victim);
*/
    {
          string parry_string = SKILL_D(parry_skill)->query_parry_msg(limb,victim,me);
          if(functionp(parry_string)) parry_string = evaluate(me,victim);
          if(parry_string)
            result += parry_string;
          else
            result += SKILL_D("parry")->query_parry_msg(weapon);
    }
        /*
		else if (SKILL_D(parry_skill)->query_parry_msg(limb))
		    result += SKILL_D(parry_skill)->query_parry_msg(limb);
		else result += SKILL_D("parry")->query_parry_msg(weapon);
*/
		// 反擊架構 by swy
		if((victim->query("class")=="bonze"||victim->query("class")=="bandit"||victim->query("id")=="swy")
		  && victim->query_skill("counter",1)>random(200) && attack_type!=TYPE_QUICK) {
		    victim->set_temp("can_contour",1); }
	    } else if(!me->query_temp("weapon")&&!victim->query_temp("weapon")) {
		result += SKILL_D("parry")->query_parry_msg();
		// 反擊架構 by swy
		if((victim->query("class")=="bonze"||victim->query("class")=="bandit"||victim->query("id")=="swy")
		  && victim->query_skill("counter",1)>random(200) && attack_type!=TYPE_QUICK) {
		    victim->set_temp("can_contour",1); }
	    } else {
		result += HIR+"$n沒有"+HIW+"兵器"+HIR+"卸開敵人"+HIC+"武器"+HIR+"，因此中招受傷了。\n"+NOR;
		victim->set_temp("no_weapon_parry",1); }
	    damage = RESULT_PARRY;
	} else {
	    // 打到敵人內力的影響 by swy
	    if( my["force_factor"]>0 && my["force"]>=my["force_factor"]) {
		my["force"] -= my["force_factor"];
		fap = skill_power(me, "force");
		fdp = skill_power(victim, "force");
		// 有內力影響,被擋開
		if( your["force_factor"] > 0 &&
		  random(fap + fdp) < fdp ) {
		    damage_bonus = 0;
		    result += "但是$N招式所含的內勁被$n的護身氣勁所化解﹐";
		    if( fdp < random(fap) && userp(me) )
			victim->improve_skill("force", 1);
		}
		// 有內力影響, 打到了
		else {
		    // 沒有 class ppl 的 skills force 以最高 50 來計算 by swy
		    // 沒有 class npc 的 skills force 以最高 700 來計算 by swy
		    class1=my["class"];
		    divv=force_div[class1];
		    if(!divv && !userp(me) && action["force"]) {
			divv=action["force"];
			if(!divv) divv=100;
			if(divv>700) divv=700;
		    } else if(!divv && !userp(me)) {
			divv=100;
		    } else { if(!divv && userp(me)) divv=50; }

		    damage_bonus+=(int)(my["force_factor"]*divv*0.15);
		}
	    }
	    
	    if( damage_bonus > 0
	      && your["force_factor"] > 0
	      && your["force"] >= your["force_factor"] ) {
		if( living(victim) ) result += "$N的內勁擊潰了$n身上的護身真氣﹐";
		else                 result += "$n身上的真氣自然地生出一股抗拒的氣勁﹐";
		power_dam = your["max_force"];
		damage_bonus -= (power_dam / 10);
		your["force"] -= your["force_factor"];
	    }
	    
	    damage_bonus -= (int)victim->query_temp("apply/armor_vs_force");
	    damage_bonus -= (int)(dp/150);
	    // =============================================================
	    //    (6) Apply the damage bonus to the damage we'll inflict.
	    //        把傷害值加上去
	    //
	    
	    if( damage_bonus > 0 )
		damage += (int)damage_bonus;
	    else damage = damage;
	    
	    if( attack_type == TYPE_QUICK )
		damage += 100;
	    
	    // 優惠新玩家一天
	    
	    if( userp(me) )
		if( me->query("mud_age") < 10800 ) {
		    damage += (int) my["str"];
		    message_vision(HIY + "只見$N身旁環繞著一圈紅光, "+
		      "$N的力量增強了!。\n" + NOR, me);
		}
	    else if( me->query("mud_age") < 11400 )
		message_vision(HIY + "$N身旁的紅光漸漸暗淡下來, "+
		  "趨近於平淡。\n" + NOR, me);
	    // 把傷害力加上攻擊力,在減調防禦力為新傷害力 by swy
	    damage += (ap/100);
	    damage -= (op/100);
	    if(userp(me)) {
		damage=(int)damage;
	    } else { damage=(int)damage*0.85; }
	    if(damage<=0) damage=100;
	    if( victim->query_temp("losehurt")==1 )
	    { damage=(int)(damage/2); }
	    if( victim->query_temp("lightinjury")==1 )
	    { damage=(int)(damage*3/5); }

	    if (victim->query_temp("unsuck")==1)
	    {
		message_vision(HIY + "\n『金鐘罩』十成功\力，果然厲害，竟把$N加諸在$n的攻擊全數反震回去。\n" + NOR,me,victim);
		me->add("kee",-(damage));
		me->add("eff_kee",-(damage));
		report_status(me);
		if(damage > 0) damage=0;
		victim->delete_temp("unsuck");
	    }
	    if (victim->query_temp("goldheal")==1)
	    {
		message_vision(HIY + "\n只聽見ㄎ_ㄧ_ㄤ一聲，$N的攻勢盡被$n的『金鐘罩』化去。\n" + NOR,me,victim);
		if(damage > 30) damage=30;
		victim->delete_temp("goldheal");
	    }
	    if (me->query_temp("powerup")==1 ) {
		damage += 250;
	    }
	    if (me->query_temp("mightup")==1 ) {
		damage += 200;
	    }

	    if (me->query_temp("keeup")==1 ) {
		damage = damage*3/4;
	    }
	    if (me->query_temp("hpup")==1 ) {
		damage = damage*4/5;
	    }

	    //劍聖昊玥罡氣 降攻增防部分 by appo
	    //降攻部分在skill sun_moon_sword.c 部分已增加
	    //所有副攻威力減半
	    if (victim->query_temp("sun-moon"))
	    {
		message_vision(HIY + "$n的昊玥罡\氣發出萬丈光芒，卸開$N對$n的部分攻擊!!\n" + NOR,me,victim);
		if(damage > 0) damage=damage/2;
		report_status(victim);
	    }
	    // 修正增加機率 by swy
	    c1=(int)my["combat_exp"];
	    c2=(int)your["combat_exp"];
	    if(c1-c2<0) { div2=0; }
	    else if(c1-c2>=4000000) { div2=40; }
	    else if(c1-c2>=3000000) { div2=30; }
	    else if(c1-c2>=2000000) { div2=20; }
	    else if(c1-c2>=1000000) { div2=10; }
	    else { div2=5; }
	    div1_2=90-div2;
	    if(div1_2<50) div1_2=50;
	    if(div1_2>random(100)) {
		if ( victim->query_temp("ref_shield")==1)
		{
		    message_vision(HIC + "\n玄冰結界" + HIM + "將$N的攻擊完全反彈回去!!\n" + NOR,me,victim);
		    me->receive_damage("kee",(damage),victim);
		    //     me->receive_wound("kee",(damage),victim);
		    //反彈就已經很強了還打最大值!?  修正之  by frequency
		    if(damage > 0) damage=0;
		    report_status(me);
		}
	    }
	    // dancer manashield 敘述
	    if (victim->query_temp("mana_shield"))
	    {
		if(damage > 0.3*(victim->query("max_kee")) || damage > 5000)
		{
		    message_vision(HIR + "\n$N的攻勢霸道無匹，強行突破了$n的" + HIW + "幻夢之翼" + HIR + "，直接對$n本體造成傷害。\n" + NOR,me,victim);
		    damage = damage/2;
		    victim->set_temp("shield_broken",1);
		}else{
		    if ( victim->query_temp("mana_shield")==1)//dancer
		    {
			message_vision(HIW + "\n幻夢之翼隱約而現，柔若棉絮，輕輕地將$N攻擊化歸於無形!!\n" + NOR,me,victim);
			if(damage > 0) damage=damage/2;
			report_status(victim);
		    }
		    if ( victim->query_temp("mana_shield2")==1)//non dancer
		    {
			message_vision(HIY + "\n幻夢之翼隱約而現，柔若棉絮，輕輕地將$N攻擊減弱不少!!\n" + NOR,me,victim);
			if(damage > 0) damage=damage*2;
			report_status(victim);
		    }
		    if ( victim->query_temp("mana_shield3")==1)//fighter,prayer
		    {
			message_vision(HIY + "\n幻夢之翼隱約而現，柔若棉絮，輕輕地將$N攻擊減弱不少!!\n" + NOR,me,victim);
			if(damage > 0) damage=damage*4;
			report_status(victim);
		    }
		    if ( victim->query_temp("mana_shield4")==1)//mblade
		    {
			message_vision(HIY + "\n幻夢之翼隱約而現，柔若棉絮，輕輕地將$N攻擊減弱不少!!\n" + NOR,me,victim);
			if(damage > 0) damage=damage*8;
			report_status(victim);
		    }
		}
	    }
	    //power_down......by cgy....
	    if (me->query_temp("power-down")>=1)
	    {
		pod=me->query_temp("power-down");
		if (pod>16) {damage=damage/10;}
		if (pod>14&&pod<17) {damage=damage/5;}
		if (pod>12&&pod<15) {damage=damage*3/10;}
		if (pod>10&&pod<13) {damage=damage*4/10;}
		if (pod>8&&pod<11) {damage=damage*5/10;}
		if (pod>6&&pod<9) {damage=damage*6/10;}
		if (pod>4&&pod<7) {damage=damage*7/10;}
		if (pod>2&&pod<5) {damage=damage*8/10;}
		if (pod>0&&pod<3) {damage=damage*9/10;}
	    }
	    
	    //Dancer吸收攻擊 by frequency 
	    if ( victim->query_temp("absorb")==1)
	    {
		message_vision(HIW + "\n玄陰之氣如水般柔和綿密，將$N的攻擊轉化為$n的內勁。\n" + NOR,me,victim);
		victim->add("force",damage/4);
		if(damage > 0) damage=damage/5;
	    }
	    if (victim->query_temp("absorb")==2)
	    {
		message_vision(HIW + "\n玄陰之氣如水般柔和綿密，將$N的攻擊轉化為$n的靈力。\n" + NOR,me,victim);
		victim->add("atman",damage/3);
		if(damage > 0) damage=damage/5;
	    }
	    if (victim->query_temp("absorb")==3)
	    {
		message_vision(HIW + "\n玄陰之氣如水般柔和綿密，將$N的攻擊轉化為$n的生命之源。\n" + NOR,me,victim);
		victim->add("kee",damage/2);
		if(damage > 0) damage=damage/5;
	    }
	    
	    if (victim->query_temp("rainbow-steps")==1 && random((int)victim->query("functions/rainbow-steps/level",1))>60)
	    {
		message_vision(HIY + "\n$n" + NOR + "使出月影微步終極舞步" + HIW + "～" + HIM + "七彩幻夢" + NOR + ",手中七彩緞帶幻成一道彩虹射向" + HIB + "$N！\n" + NOR,me,victim);
		message_vision(HIY + "                $n" + HIR + "其本身如" + HIG + "靈蛇欺敵般的躲過" + HIY + "$N" + HIR + "的凌厲攻擊。。\n" + NOR,me,victim);
		if(damage > 0) damage=0;
	    }
	    if (victim->query_temp("snake-steps")==1 && random((int)victim->query("functions/snake-steps/level",1))>70)
	    {
		message_vision(HIC + "\n$n" + HIR + "身影幻化萬千向四方流竄,形影迷離令" + HIY + "$N" + HIR + "的攻勢狂擊殘影。！\n" + NOR,me,victim);
		message_vision(HIG + "  結果「嗤」地一聲﹐七彩光芒從" + HIB + "$N" + HIG + "的身上穿透而出, 令" + HIB + "$N" + HIG + "迷失景象。\n" + NOR,me,victim);
		message_vision(HIY + "                $n" + HIC + "趁機閃過" + HIB + "$N" + HIC + "凶猛的攻擊。\n" + NOR,me,victim);
		if(damage > 0) damage=0;
	    }
	    if (victim->query_temp("adv-dodge")==1)
	    {
		message_vision(HIY + "\n$n使出" + HIG + "☆俠影步☆" + HIY + "以迅捷無比的速度閃過$N的攻擊並贊上一擊將$N重創。\n" + NOR,me,victim);
		me->add("kee",-(damage));
		report_status(me);
		if(damage > 0) damage=0;
	    }
	    if(me->query_temp("kang-power")==1) {
		message_vision(HIW + "$N的『烈燄浩氣』聚氣於力，使$N的威力增加不少。\n" + NOR,me);
		damage += 350;
	    }
			if (victim->query_temp("hardshell") ) {
							if(userp(victim)) {
											if(victim->query("class","taoist") )
											{
															if( damage > 10 ) damage = 10;
											}
											else
											{
															damage  = damage / 3 ;
															if(damage < 10) damage = 10;
											}
							}
							else if( damage > 10 ) damage = 10;
        
	    }
	    if(victim->query_temp("hwa_je")){
		if(damage >0) damage=0;
	    }
	    if (me->query_temp("addpower")==1)
	    {
		damage += 1500;
		me->delete_temp("addpower");
	    }
	    if (me->query("mpower")) {
		damage += 300;
	    }
	    // 發現一個 bug 自創招式對 fighter 沒用反而減低 damage
	    // 但是對其他門派卻有天壤之別 如果一般 class damage 有 1000
	    // 那 1000 * my_skill_power 會很可怕   因為 my_skill_power 最高可以 8
	    // 那 1000 * 8 = 8000 不就等於叫 fighter 去死嗎
	    // 不過為了獎勵加個 100 就好了     by swy
	    if(me->query("env/my_skill")) {
		damage=damage+100;
	    } else {
		if(userp(me) && userp(victim)) { damage = damage; }
		else { damage=(int)damage*0.85; } }
	    // 射手系統 part 2  by swy
	    // 射中右或左手 damage 減半  射中左右手 damage = 0
	    // 左右手都受傷當然沒威力  很合理   要把傷治愈打算給 doctor 此功能
	    if(me->query_temp("over/right")==1&&me->query_temp("over/left")==1) {
		damage=30;
		tell_object(me,HIC + "你雙手受傷毫無傷害力可言!\n" + NOR);
	    } else if(me->query_temp("over/right")==1||me->query_temp("over/left")==1) {
		damage /= 2;
		tell_object(me,HIR + "你手受傷傷害力驟減一半!\n" + NOR);
	    }

	    victim->set_temp("no_armor_effect",1);
	    result += damage_msg(damage, action["damage_type"]);
	    //2001.11.1 下面的部分 殺手的第四階段進階 幻之忍殺的專屬技巧 分影術的動作
	    //        發動機率是寫在dodge那邊，發動之後就會有%讓damage變0
	    //2002.04.04 修正邏輯上的錯誤
	    if (victim->query_temp("shadowfun") > 0)
	    {
		switch ( victim->query("dark-steps/shadow/lv") )
		{
		case 0..10 : //50%
		    if (random (100) > 50)
		    {
			message_vision(HIW + "\n$n 按照五行八卦的步法，在整個空間中幻化出無限的身影," + HIY + "$N" + HIW + "根本無從攻擊起。！\n" + NOR,me,victim);
			damage = 0;              
		    }
		    break;
		case 11..40 : //60%
		    if (random (100) > 40)
		    {
			message_vision(HIW + "\n$n 按照五行八卦的步法，在整個空間中幻化出無限的身影," + HIY + "$N" + HIW + "根本無從攻擊起。！\n" + NOR,me,victim);
			message_vision(HIW + "$N 瘋狂的往幻影攻擊而去,$n絲毫有受到一點傷害。\n" + NOR,me,victim);
			me->receive_damage("gin", 150 , victim );
			damage = 0;
		    }
		    break;
		case 41..70 :
		    if (random (100) > 30)
		    {
			message_vision(HIW + "\n$n 按照五行八卦的步法，在整個空間中幻化出無限的身影," + HIY + "$N" + HIW + "根本無從攻擊起。！\n" + NOR,me,victim);
			message_vision(HIW + "$N 瘋狂的往幻影攻擊而去,$n絲毫沒有受到一點傷害。\n" + NOR,me,victim);
			me->receive_damage("gin", random(150)+150 , victim );
			damage = 0;
		    }
		    break;
		case 71..100:
		    if (random (100) > 20)
		    {
			message_vision(HIW + "\n$n 按照五行八卦的步法，在整個空間中幻化出無限的身影," + HIY + "$N" + HIW + "根本無從攻擊起。！\n" + NOR,me,victim);
			message_vision(HIW + "光影不斷的在" + HIG + "$N" + HIW + "的身邊環繞, 令" + HIG + "$N" + HIW + "感到無限的恐懼\n" + NOR,me,victim);
			message_vision(HIR + "$n" + HIW + "所使出的分影術，讓" + HIG + "$N" + HIW + "根本不知道如何發動攻勢。\n" + NOR,me,victim);
			me->receive_damage("gin", random(250)+150 , victim );
			me->start_busy(1);
			damage = 0;
		    }
		    break;
		case 101..150: //專家級，只有特殊獎勵，才可以升到此級
		    if (random (100) > 10)
		    {
			message_vision(HIW + "\n$n 按照五行八卦的步法，在整個空間中幻化出無限的身影," + HIY + "$N" + HIW + "根本無從攻擊起。！\n" + NOR,me,victim);
			message_vision(HIW + "光影不斷的在" + HIG + "$N" + HIW + "的身邊環繞, 令" + HIG + "$N" + HIW + "感到無限的恐懼\n" + NOR,me,victim);
			message_vision(HIR + "$n" + HIW + "所使出的分影術，讓" + HIG + "$N" + HIW + "根本不知道如何發動攻勢。\n" + NOR,me,victim);
			message_vision(HIW + "$N 瘋狂的往幻影攻擊而去,$n絲毫沒有受到一點傷害。\n" + NOR,me,victim);
			me->receive_damage("gin", random(400)+150 , victim );
			me->start_busy(1);
			damage = 0;
		    }
		    break;
		default: //巫師才有可能這一級
		    me->receive_damage("gin", random(1999)+600 , victim );
		    me->start_busy(2);
		    damage =0;
		}
		//不管有沒有發動成功，都要扣掉
		victim->add_temp("shadowfun",-1);
	    }
	    
	    
	    // 我覺得照 class 特色 swordsman and blademan 可以傷最大值
	    // 所以我調整 swordsman and blademan 素招就能傷害最大值 by swy
	    if(me->query("class")=="swordsman" || me->query("class")=="blademan") {
		damage = victim->receive_wound("kee",damage,me); } else {
		damage = victim->receive_damage("kee", damage, me ); }
	    
	    if( weapon ) weapon->hit_ob(victim, damage);
	    else me->hit_ob(victim, damage);
	    
	    // Gain combat_exp.
	    
	    if( ap < dp && (!userp(me) || !userp(victim))
	      && random(my["gin"]*100/my["max_gin"] + my["int"]) > 30 ) {
		my["combat_exp"] += 1;
		my["potential"] += 1;
		me->improve_skill(attack_skill, 1);
	    }
	    
	    if( (!userp(me) || !userp(victim))
	      && random(your["max_kee"] + your["kee"]) < damage ) {
		your["combat_exp"] += 1;
		your["potential"] += 1;
	    }
	}
    }
    result = replace_string( result, "$l", limb );
    
    if( objectp(weapon) ) {
	result = replace_string( result, "$w", weapon->name() );
	if( weapon->query("can_hold") )
	    arrow_path = weapon->query("arrow/path");
	if( stringp(arrow_path) )
	    result= replace_string( result, "$c",arrow_path->name() );
    }
    else if( stringp(action["weapon"]) )
	result = replace_string( result, "$w", action["weapon"] );
    else 
  	  result = replace_string( result, "$w", "雙拳" );
    
    
    
    
    
    bssone=sizeof(result);
    if(bssone >=8192)
    {
	rstrtwo=result[8000..(bssone-1)];
	rstrone=result[0..7999];
	message_vision(rstrone,me,victim,"combat");
	message_vision(rstrtwo,me,victim,"combat");
    }
    
    else {
      	message_vision(result, me, victim ,"combat");
    }
    if( damage > 0 ) report_status(victim);
    if( damage > 0 ) report_kee(victim);
    // 武者自動衝封穴系統 by swy 請 wiz 別把條件說出去 thx
    if(!userp(me)) cmexp=(int)me->query("combat_exp")/2;
    else cmexp=(int)me->query("combat_exp")*4/5;
    // 1.先檢查是否為 ppl
    if(userp(victim)
      // 2.再檢查 exp
      && random(cmexp)<random(victim->query("combat_exp"))
      // 3.檢查是否 busy
      && victim->is_busy()
      // 4.再檢查內功等級高低
      && me->query_skill("force")<victim->query_skill("force")
      // 5.再檢查要衝穴所需的真氣值(因為真氣可 bet 所以設高一點)
      && victim->query("force")>5000
      // 6.再檢查機率
      && random(100)>50
      // 7.檢查會衝穴的 exp 限制
      && victim->query("combat_exp")>3000000
      // 8.多加一個想用再用的條件
      && victim->query("env/衝穴")=="YES"
      // 9.最後檢查要 fighter
      && victim->query("class")=="fighter") {
	message_vision(HIW + "\n只見$N暴起所有" + HIY + "真氣內勁" + HIW + "，$N全身隴罩在一股" + HIC + "綻藍氣勁" + HIW + "中，赫然已解開身上被封的穴道。\n" + NOR,victim);
	message_vision(HIW + "$N驚愕之時，$n聚集所有" + HIY + "真氣內勁" + HIW + "，把$N隴罩在一股" + HIC + "綻藍氣勁" + HIW + "中，$N受到強大氣勁壓迫行動受阻。\n" + NOR,me,victim);
	victim->delete_busy();
	me->start_busy(1);
	if(victim->query("force")>5000) { victim->add("force",-5000); }
	else { victim->set("force",0); }
    }
    if(victim->query_temp("no_weapon_parry")==1&&victim->query("kee")>0) {
	victim->receive_damage("kee",250,me);
	victim->delete_temp("no_weapon_parry"); }
    if( victim->query_temp("can_contour")==1 ) {
	message_vision(HIW + "\n$N使出" + HIR + "霸王卸甲" + HIW + "藉由招架$n攻擊之時﹐全神貫注趁機發動反擊﹗\n" + NOR,victim,me);
	do_attack(victim, me, victim->query_temp("weapon"));
	victim->delete_temp("can_contour");
    }
    if(!me->query("env/my_skill") || choose_skill == -1 || me->query("combat_exp") < 30000000) {    //修正使用自己的招式時..不出現原有招式的特功!!!!
	if(me->query("force") > 1) {
	    if( functionp(action["post_action"]) )
		evaluate( action["post_action"], me, victim, weapon, damage);
	    
	    action = me->query("force_actions");
	    
	    if( mapp(action) )
		if( functionp(action["post_action"]) )
		    evaluate( action["post_action"], me, victim, weapon, damage);
	} else tell_object(me,"你的內力不足以驅動武學附加攻擊!");
    }//以上
    action = me->query("weapon_actions");  //武器的部份!!!!
    
    if( mapp(action) )
	if( functionp(action["post_action"]) )
	    evaluate( action["post_action"], me, victim, weapon, damage);
    
    
    // Add By Oda 96/7/11
    // 如果玩家組 team 打 mob 的時候, 人際關係會增加
    if( pointerp(t=me->query_team()) ) {
	if( me->is_team_leader() ) {
	    for( i=1; i<sizeof(t); i++ )
		if(t[i])
		    me->add("人際關係/"+t[i]->query("id"),1);
	} else
	if(t[0])
	    me->add("人際關係/"+t[0]->query("id"),1);
    }
    
    // See if the victim can make a riposte.
    
    if( attack_type==TYPE_REGULAR
      && damage < 1
      && victim->query_temp("guarding") ) {
	victim->set_temp("guarding", 0);
	if( random(my["cps"]) < 10 ) {
	    message_vision("$N一擊不中﹐露出了破綻﹗\n", me);
	    do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
	}
	else {
	    message_vision("$N見$n攻擊失誤﹐趁機發動攻擊﹗\n", victim, me);
	    do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
	}
    }
    if( userp(victim) ) {
	ID = geteuid(victim);
	file = sprintf("exp/%s/%s", ID[0..0], ID);
	if(!victim->query("exp/first_exp"))
	{
	    victim->set("exp/first_exp",1);
	    log_file(""+file,sprintf("%s 第一次得到經驗值(%d)的紀錄於 %s\n",victim->name(1)+"("+ID+")",victim->query("combat_exp"),ctime(time())));
	}
	if( !victim->query("exp/get_exp") && victim->query("combat_exp") >= 100000 )
	{
	    victim->set("exp/get_exp",(int)(victim->query("combat_exp")/100000) );
	    log_file(""+file,sprintf("%s 第一次登記經驗值的紀錄於 %s\n",victim->name(1)+"("+ID+")",ctime(time())));
	}
	if( ((int)(victim->query("combat_exp")/100000) == victim->query("exp/get_exp")) && victim->query("exp/get_exp")>0 )
	{
	    if(victim->query("combat_exp")>=100000000 && victim->query("exp/get_exp")%1000==0)
		log_file(""+file,sprintf("%s 經驗值升到 (%s億) 於 %s\n",victim->name(1)+"("+ID+")",CHINESE_D->chinese_number((victim->query("exp/get_exp"))/1000),ctime(time())));
	    else if(victim->query("combat_exp")>=100000000 && victim->query("exp/get_exp")%1000<100)
		log_file(""+file,sprintf("%s 經驗值升到 (%s億零%s萬) 於 %s\n",victim->name(1)+"("+ID+")",CHINESE_D->chinese_number((victim->query("exp/get_exp"))/1000),CHINESE_D->chinese_number((victim->query("exp/get_exp")%1000)*10),ctime(time())));
	    else if(victim->query("combat_exp")>=100000000)
		log_file(""+file,sprintf("%s 經驗值升到 (%s億%s萬) 於 %s\n",victim->name(1)+"("+ID+")",CHINESE_D->chinese_number((victim->query("exp/get_exp"))/1000),CHINESE_D->chinese_number((victim->query("exp/get_exp")%1000)*10),ctime(time())));
	    else
		log_file(""+file,sprintf("%s 經驗值升到 (%14s萬) 於 %s\n",victim->name(1)+"("+ID+")",CHINESE_D->chinese_number((victim->query("exp/get_exp"))*10),ctime(time())));
	    victim->add("exp/get_exp",1);
	}
	if(((int)(victim->query("combat_exp")/100000) > victim->query("exp/get_exp")))
	    victim->set("exp/get_exp",victim->query("combat_exp")/100000 + 1);
    } 
    if( userp(me) ) {
	ID = geteuid(me);
	file = sprintf("exp/%s/%s", ID[0..0], ID);
	if(!me->query("exp/first_exp"))
	{
	    me->set("exp/first_exp",1);
	    log_file(""+file,sprintf("%s 第一次得到經驗值(%d)的紀錄於 %s\n",me->name(1)+"("+ID+")",me->query("combat_exp"),ctime(time())));
	}
	if( !me->query("exp/get_exp") && me->query("combat_exp") >= 100000 )
	{
	    me->set("exp/get_exp",(int)(me->query("combat_exp")/100000) );
	    log_file(""+file,sprintf("%s 第一次登記經驗值的紀錄於 %s\n",me->name(1)+"("+ID+")",ctime(time())));
	}
	if( ((int)(me->query("combat_exp")/100000) == me->query("exp/get_exp")) && me->query("exp/get_exp")>0 )
	{
	    if(me->query("combat_exp")>=100000000 && me->query("exp/get_exp")%1000==0)
		log_file(""+file,sprintf("%s 經驗值升到 (%s億) 於 %s\n",me->name(1)+"("+ID+")",CHINESE_D->chinese_number((me->query("exp/get_exp"))/1000),ctime(time())));
	    else if(me->query("combat_exp")>=100000000 && me->query("exp/get_exp")%1000<100)
		log_file(""+file,sprintf("%s 經驗值升到 (%s億零%s萬) 於 %s\n",me->name(1)+"("+ID+")",CHINESE_D->chinese_number((me->query("exp/get_exp"))/1000),CHINESE_D->chinese_number((me->query("exp/get_exp")%1000)*10),ctime(time())));
	    else if(me->query("combat_exp")>=100000000)
		log_file(""+file,sprintf("%s 經驗值升到 (%s億%s萬) 於 %s\n",me->name(1)+"("+ID+")",CHINESE_D->chinese_number((me->query("exp/get_exp"))/1000),CHINESE_D->chinese_number((me->query("exp/get_exp")%1000)*10),ctime(time())));
	    else
		log_file(""+file,sprintf("%s 經驗值升到 (%14s萬) 於 %s\n",me->name(1)+"("+ID+")",CHINESE_D->chinese_number((me->query("exp/get_exp"))*10),ctime(time())));
	    me->add("exp/get_exp",1);
	}
	if(((int)(me->query("combat_exp")/100000) > me->query("exp/get_exp")))
	    me->set("exp/get_exp",me->query("combat_exp")/100000 + 1);
    }
}

//      fight()
//
//      This is called in the attack() defined in F_ATTACK, which handles fighting
//      in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
    object ob;
    int i;
    if( !living(me) ) return;
    if (!me->visible(victim)
      && (random(100 + (int)me->query_skill("perception")) < 100) )
	return;
    // If victim is busy or unconcious, always take the chance to
    //   make an attack.
    if( victim->is_busy() || !living(victim) ) {
	me->set_temp("guarding", 0);
	do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    } else if(me->query("class")=="swordsman"&&victim->query("class")!="swordsman"
      && !me->query_temp("delay_fight"))
    {
	me->set_temp("guarding", 0);
	me->set_temp("delay_fight",1);
	do_attack(me, victim, me->query_temp("weapon"));
    } else if(me->query("class")!="swordsman"&&victim->query("class")=="swordsman"
      && !victim->query_temp("delay_fight"))
    {
	me->set_temp("guarding", 0);
	victim->set_temp("delay_fight",1);
	do_attack(victim, me, victim->query_temp("weapon"));
    } else if( random( (int)victim->query_cps() * 3 ) <
      ((int)me->query_cor() + (int)me->query("bellicosity") / 50) )
    {
	me->set_temp("guarding", 0);
	do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
  if(me->query("class") == "blademan") {
    // 左手武器攻擊
    if(me->query_temp("secondary_weapon") && me->query_skill("secondary_blade")) {
      do_attack(me, victim, me->query_temp("secondary_weapon"), TYPE_SECOND_HAND);
    }
    // 右手武器攻擊
    if(me->query_temp("third_weapon") && me->query_skill("third_blade")) {
      do_attack(me, victim, me->query_temp("third_weapon"), TYPE_THIRD_HAND);
    }
  }

	// Else, we just start guarding.
    } else if( me->query_temp("guarding")==0 ) {
	me->set_temp("guarding", 1);
	message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
	return;
    } else return;
    
    // Make sure the victim had noticed the attack.
    if( !victim->is_fighting(me) ) victim->fight_ob(me);
}

//      auto_fight()
//      This function is to start an automatically fight. Currently this is
//      used in "aggressive", "vendetta", "hatred", "berserk" fight.
void auto_fight( object me, object obj, string type )
{
    // Don't let NPC autofight NPC.
    if( !userp(me) && !userp(obj) ) return;
    
    // Because most of the cases that we cannot start a fight cannot be checked
    // before we really call the kill_ob(), so we just make sure we have no
    // aggressive callout wating here.
    if( me->query_temp("looking_for_trouble") ) return;
    me->set_temp("looking_for_trouble", 1);
    
    // This call_out gives victim a chance to slip trough the fierce guys.
    

    call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
    int bellicosity;
    
    if( !me ) return;                               // Are we still exist( not becoming a corpse )?
    
    me->delete_temp("looking_for_trouble");
    if( !obj ) return;
    
    if(     me->is_fighting(obj)                            // Are we busy fighting?
      ||      !living(me)                                                     // Are we capable for a fight?
      ||      environment(me)!=environment(obj)       // Are we still in the same room?
      ||      environment(me)->query("no_fight")      // Are we in a peace room?
    )       return;
    
    bellicosity = (int)me->query("bellicosity");
    if(!wizardp(me)) {
	message_vision("$N用一種異樣的眼神掃視著在場的每一個人。\n", me);
    }
    
    if( (int)me->query("force") > (random(bellicosity) + bellicosity)/2 )
	return;
    
    // 修改一下為不會砍馬  但其他的mob照砍  By Swy
    if( bellicosity > (int)obj->query("score") && !wizardp(obj) && living(obj) ) {
	message_vision( "$N對著$n喝道﹕" + RANK_D->query_self_rude(me)
	  + "看你實在很不順眼﹐去死吧。\n", me, obj);
	me->kill_ob(obj);
    }
    else {
	message_vision( "$n的正義之氣散發全身, 使$N不敢侵犯傷害$n。\n", me, obj );
    }
}

void start_hatred(object me, object obj)
{
    if( !me ) return;                               // Are we still exist( not becoming a corpse )?
    
    me->delete_temp("looking_for_trouble");
    if( !obj ) return;
    
    if(     me->is_fighting(obj)                            // Are we busy fighting?
      ||      !living(me)                                                     // Are we capable for a fight?
      ||      environment(me)!=environment(obj)       // Are we still in the same room?
      ||      environment(me)->query("no_fight")      // Are we in a peace room?
    )       return;
    
    // We found our hatred! Charge!
    message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
    me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
    if( !me ) return;                               // Are we still exist( not becoming a corpse )?
    
    me->delete_temp("looking_for_trouble");
    if( !obj ) return;
    
    if(     me->is_fighting(obj)                            // Are we busy fighting?
      ||      !living(me)                                                     // Are we capable for a fight?
      ||      environment(me)!=environment(obj)       // Are we still in the same room?
      ||      environment(me)->query("no_fight")      // Are we in a peace room?
    )       return;
    
    // We found our vendetta opponent! Charge!
    me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
    if( !me ) return;                               // Are we still exist( not becoming a corpse )?
    
    me->delete_temp("looking_for_trouble");
    if( !obj ) return;
    
    if(     me->is_fighting(obj)                            // Are we busy fighting?
      ||      !living(me)                                                     // Are we capable for a fight?
      ||      environment(me)!=environment(obj)       // Are we still in the same room?
      ||      environment(me)->query("no_fight")      // Are we in a peace room?
    )       return;
    
    // We got a nice victim! Kill him/her/it!!!
    me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
    // 可以在 npc 身上設 set_temp("die","xxxxxxx");
    // 或 set_temp("die",(: die_msg :) );
    // 這樣在 npc 死後會顯示該訊息。
    // 不過，也 可以透過物件的 void init() 來設定。
    // added by wade 87/9/9
    mixed die_msg;
    
    switch(event) {
    case "dead" :
	if( !undefinedp( die_msg = ob->query_temp("die") ) ) {
	    if( stringp(die_msg) )
		message( "sound", die_msg, environment (ob) );
	    else if( functionp(die_msg) )
		evaluate(die_msg);
	}
	else
	    // 到這行前都是增加進來的
	    message_vision("\n$N死了。\n\n", ob);
	break;
    case "unconcious":
	message_vision("$N腳下一個不穩﹐跌在地上一動也不動了。\n\n", ob);
	break;
    case "revive":
	message_vision("\n$N慢慢睜開眼睛﹐清醒了過來。\n\n", ob);
	break;
    }
}

void killing (object who)
{
    object        where, cop_head;
    
    where = environment (who);
    
    if (!cop_head=find_living("cop head"))
	if (cop_head = new(COP_HEAD))
	    cop_head->move(where);
    else
    if (!cop_head->is_fighting()) cop_head->move(where);
}

void winner_reward(object killer, object victim)
{
    killer->defeated_enemy(victim);
}

void killer_reward(object killer, object victim)
{
    //PK的部份重新改寫 by Chan 9/18/98
    int bls,pktime,pkmoney;
    string vmark,pktitle,death_str;
    
    // Call the mudlib killer apply.
    if (victim)
	killer->killed_enemy(victim);
    else
	killer->killed_enemy(killer);
    
    if( userp(victim) ) { //死的人是player的話.....以下做
	if(userp(killer)) //killer是玩家才執行下面的
	{
	    if((!victim->query("pker"))&&(!victim->query("ckill")))
	    { //殺死的人是pker或ckill的話就不算pk
		if(killer->query("id")!=victim->query("id"))
		{//自己殺死自己不算pk
		    // pk設定的部份 by Chan
		    pktime = 1800; //設定三十分鐘不能離線 by chan
		    pktime += time();//算出系統時間+三十分鐘 by chan
		    killer->set("PKTIME",pktime);  //把時間設為永久儲存的by bss
		    if(!killer->query("pker"))
		    { //如此設法是怕第二次pk..把好的title給蓋了 by chan 11/24
			pktitle=killer->query("title");
			killer->set("PKNAME",pktitle);
		    }
		    killer->set("title",HIR + "殺人兇手" + NOR);
		    tell_room(killer,HIR + "你殺了線上玩家,成了殺人兇手了。\n" + NOR);
		    killer->set("pker",1);
		}
		killer->add("PKS", 1);
		// by ACKY
		if( victim->query("combat_exp")>=3000000 )
		    killer->add("HKS", 1);
	    }
	    else{
		pkmoney=victim->query("combat_exp");//根據pker的exp給予kill
		pkmoney=pkmoney*10;//如果是exp一百萬就是1000 gold
		killer->add("coin",pkmoney);//pker的人錢
		tell_room(killer,HIW + "你為民除害,殺了殺人兇手,得到了一筆酬金。\n" + NOR);
	    }//pker死後就不算pker及解除追緝狀態
	}
	// modify by oda, pk 玩家不加殺氣
	// bls = 10;
	bls = 0;
	switch( random(7) ) { // by ACKY
	case 1:
	    CHANNEL_D->do_channel( killer, "dead",
	      sprintf( "狂笑說:「可憐的%s, 回家向你的母親哭訴吧。」", victim->name(1) ) );
	    break;
	case 2:
	    CHANNEL_D->do_channel( killer, "dead",
	      sprintf( "恥笑著:「無能的%s, 你還有膽來一次嗎?」", victim->name(1) ) );
	    break;
	case 3:
	    CHANNEL_D->do_channel( killer, "dead",
	      sprintf( "高喊著:「哇哈哈, 有誰願意幫%s收屍啊!」", victim->name(1) ) );
	    break;
	case 4:
	    CHANNEL_D->do_channel( killer, "dead",
	      sprintf( "大笑著:「天底下居然還有像%s這麼自不量力的人!」", victim->name(1) ) );
	    break;
	case 5:
	    CHANNEL_D->do_channel( killer, "dead",
	      sprintf( "狂笑說:「看著%s鮮血亂噴, 真是一種無上的享受!」", victim->name(1) ) );
	    break;
	case 6:
	    CHANNEL_D->do_channel( killer, "dead",
	      sprintf( "大喊著:「%s, 我還可以再殺你一次, 只要你敢來的話!」", victim->name(1) ) );
	    break;
	default:
	    CHANNEL_D->do_channel( killer, "dead",
	      sprintf( "狂笑著:「哇哈哈, 我隨隨便便就把%s殺掉了！」", victim->name(1) ) );
	}
	
	death_str="";
	death_str=victim->query("id")+victim->name(1)+"被"+killer->query("id")+killer->name(1)+"所殺在"+ctime(time())+sprintf("有%d個替身!!\n",victim->query("standby"));
	write_file("/open/death/death_record",death_str);
    }
    else {
	killer->add( "MKS", 1 );
	if( victim->query("combat_exp")>=10000000 )
	    killer->add( "HKS", 1 );
	bls = 1;
    }
    
    killer->add("bellicosity", bls );
    
    if( stringp(vmark = victim->query("vendetta_mark")) )
	killer->add("vendetta/" + vmark, 1);
}

//因為有起死回生之術了，所以人死扣值必需是在黑白無常送人回人間時扣
//我把扣值的部份寫在這 by bss
int death_effect(object victim)
{
    string pktitle;
    if(!victim) return 0;
    if(victim->query("pker")) //死的人是殺人犯，pker的exp扣二次....
    {
	pktitle=victim->query("PKNAME"); //把title給送回來...
	victim->set("title",pktitle);
	victim->skill_death_penalty();
	victim->add("combat_exp", -(int)victim->query("combat_exp") / 10);
    }
    victim->set("pker",0);
    victim->delete("ckill");
    victim->delete("ckill_id"); //取消ckill所設的....by chan
    victim->set("PKTIME",0);
    //killer不是char的部份做以上的事情...
    //死的人是player也是上面在處理.....
    victim->clear_condition();
    victim->set_temp("snow-powerup",0);
    // Give the death penalty to the dying user.
    victim->set("bellicosity", 0);
    victim->add("combat_exp", -(int)victim->query("combat_exp") / 10);
    victim->delete("vendetta");
    if( (int)victim->query("potential") > (int)victim->query("learned_points"))
	victim->add("potential",
	  ((int)victim->query("learned_points") - (int)victim->query("potential"))/10 );
    victim->skill_death_penalty();
    if( userp(victim) )
	if( victim->query("exp/first_exp") && victim->query("exp/get_exp"))
	    victim->set("exp/get_exp",victim->query("combat_exp")/100000 + 1);
    return 1;
}



//
// 用來寫auto_size 的mob 之用
// modified by konn
//
int auto_size(object mob, object mob_2)
{
    object weapon = mob_2->query_temp("weapon");
    string skill, m_skill;
    int exp, gin, kee, sen, force, mana, atman, f_fac, m_fac, a_fac;
    int lv_1, lv_2, apply;
    
    /*
	    if( weapon ) skill = weapon->query("skill_type");
	    else skill = "unarmed";
    
	    lv_1 = mob_2->query_skill(skill, 1);
	    m_skill = mob_2->query_skill_mapped(skill);
	    if( m_skill )
		lv_2 = mob_2->query_skill(m_skill, 1);
    
	    lv_1 = (int) lv_1;
	    lv_2 = (int) lv_2;
	    mob->set_skill("unarmed", lv_1);
	    mob->set_skill("hell-evil", lv_2);
    
	    lv_1 = mob_2->query("dodge", 1);
	    lv_1 = (int) lv_1;
	    mob->set_skill("dodge", lv_1);
    
	    lv_1 = mob_2->query("parry", 1);
	    lv_1 = (int) lv_1;
	    mob->set_skill("parry", lv_1);
    
	    apply = mob_2->query_temp("apply/damage");
	    mob->set_temp("apply/damage", apply);
	    apply = mob_2->query_temp("apply/armor");
	    mob->set_temp("apply/armor", apply);
    
	    exp = (int) 1.5 * mob_2->query("combat_exp");
	    gin = 2 * mob_2->query("max_gin");
	    kee = 2 * mob_2->query("max_kee");
	    sen = 2 * mob_2->query("max_sen");
	    force = 2 * mob_2->query("max_force");
	    mana = 2 * mob_2->query("max_mana");
	    atman = 2 * mob_2->query("max_atman");
	    f_fac = (int) mob_2->query("force_factor");
	    m_fac = (int) mob_2->query("mana_factor");
	    a_fac = (int) mob_2->query("atman_factor");
    
	    mob->set("combat_exp", exp);
	    mob->set("gin", gin);
	    mob->set("max_gin", gin);
	    mob->set("kee", kee);
	    mob->set("max_kee", kee);
	    mob->set("sen", sen);
	    mob->set("max_sen", sen);
	    mob->set("force", force);
	    mob->set("max_force", force);
	    mob->set("mana", mana);
	    mob->set("max_mana", mana);
	    mob->set("atman", atman);
	    mob->set("max_atman", atman);
	    mob->set("force_factor", f_fac);
	    mob->set("mana_factor", m_fac);
	    mob->set("atman_factor", a_fac);
    
	    mob->delete("auto_size");
    
	    if( mob_2->is_character()     &&
		!wizardp(mob_2)           &&
		!mob_2->query("evil_mob")    ) {
		mob->kill_ob(mob_2);
		mob_2->kill_ob(mob);
	    }
    
	    mob->setup();
    */
    return 1;
}
