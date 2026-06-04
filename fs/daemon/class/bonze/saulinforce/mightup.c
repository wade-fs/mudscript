//羅漢伏魔神功 arhatforce(阿羅漢神功) 傷害+200 by blazakira
//解除效果於condition裡 做另外的設定
//由於是非戰鬥中就會刪除狀態的模式 所以 降低一些限制 及 允許戰鬥中使用fun

#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill,force,saulinforce,temp,msk,att1;
        force=me->query("max_force"); 
        saulinforce=me->query_skill("saulinforce",1);
		msk=me->query("max_s_kee",1); //作為額外增加的攻擊力 最高apply/damage+80 >> max加成的可能性為 apply/damage 280
        if (me->query("class") != "bonze")
        return notify_fail("你的職業體會不到佛法。\n");
        if( !me->query("bonze/force/arhatforce",1) )
        return notify_fail("要用阿羅漢之力得先學會羅漢伏魔神功\才行。\n");
        if( (string)me->query_skill_mapped("force")!= "saulinforce" )
        return notify_fail("阿羅漢之力要以少林內功\總綱做基礎。\n");
        if( me->query("env/force") != "羅漢伏魔神功\" && me->query("env/force") != "arhatforce")
        return notify_fail("阿羅漢之力要用羅漢伏魔神功\來啟動。\n");
        if (me->query("force") < force/20)
        return notify_fail("你的內力不夠，無法聚神使出阿羅漢之力。\n");
        if (me->query("s_kee") < 200) //因為等級最高為100 且 限制並非指最大值
        return notify_fail("你的佛法領悟不足，無法聚神使出阿羅漢之力。\n");
        if(me->query_temp("mightup")==1) 
        return notify_fail("你已經在用了。\n");
//        if( me->query("family/family_name") != "少林派")
        if(me->query("class")!="bonze")
        return notify_fail("閣下不是少林中人，不可使用！\n");
        temp=me->query("functions/mightup/level","mightup");
        skill = (temp+temp)/2;
		att1=msk * skill /1000; //為佛法 1/10 的增加倍率
		if (att1 >80) att1=80; //限制 增加數值若超過80 則以80計算 //假設佛法蹲到1000的值 則攻擊力仍為 +80
		message_vision(HBCYN + "$N靜心凝神運起羅漢伏魔神功\，使身體活化，肌肉賁起。\n" + NOR,me);
        if( skill >= saulinforce ) skill = saulinforce; //若技能等級超過內功心法則以心法為準
        if (skill > 100) skill = 100; //直接鎖死數值
		me->add("force",-msk/2);
		me->add("s_kee",-att1); //增加與佛法的相關性
//        me->set("might_exp",skill); //作為獲得經驗值的參考變數 //取消 因為每次戰鬥前 都會重新放fun 將導致此數值重新設定 故 直接在condition設定
        me->set_temp("mightup",1); //為apply/damage 200的參數
		me->set_temp("might-bonze",att1); //儲存數值予condition使用
        me->add_temp("apply/damage",att1);
		me->apply_condition("mightdown",1);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}
