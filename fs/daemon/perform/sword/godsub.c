//appo劍神分身術(godsub)
//調整by blazakira
#include <ansi.h>
inherit F_FUNCTION;
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
    int skill,force,sun_moon_force,temp;
    object soldier;
    force=me->query("max_force");
    sun_moon_force=me->query_skill("sun_moon_force",1);
    if(me->query("class")!="swordsman")
        return notify_fail("你並非劍客，不管怎麼做也無法理解劍神分身術的要訣。\n");
//以目前未開放的技能作為雙重判斷之一
    if( !me->query_skill("sun_moon_force"))
        return notify_fail("本仙技以日月兩極心法為根基來領悟。\n");
    if(me->query("swordskill/allowdiesword")!=1)
        return notify_fail("你又沒學過，怎麼會用呢？");
    if (me->query("force") < 2000 )
        return notify_fail("你的內力不足，無法使用仙技分身術～");
    if(me->query_temp("godsub")==1)
        return notify_fail("你已經施展仙技分身了，無法再分化其他分身。\n");
	temp=me->query("functions/godsub/level","godsub");
    skill = temp;
    if( skill >= sun_moon_force ) skill = sun_moon_force; //若技能等級超過心法等級時 以較低等級的心法為準
    if (skill > 100) skill = 100; //skill_lv_max=100
    me->set_temp("godsub",1);
    message_vision(HIC"$N雙臂一舉，高喝 "NOR+HIW"【仙技奧義--劍魄分身】"NOR+HIC"，只見$N身上仙雲之氣籠罩全身。\n"NOR, me);
    me->add("force", -1000);
    if (me->query("max_force")<3000)
        {
            message("vision", "你的內力不足以將體內真氣轉化為人形。\n", environment(me)); //化身失敗
            return 1; //化身失敗就跳出
        }
    seteuid(getuid()); //當系統的一個權限控管
    soldier = new("/u/b/blazakira/npc/sub.c"); //方便修正npc不消失的問題
    message_vision(HIW "只見$N閉目凝神，口中似乎唸唸有詞，瞬間只見$N身上緩緩走出一道人影。\n" NOR,me); //化身成功
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:),skill); //時間計算以技能等級為主 max=100
    soldier->set_name(me->name()+"的分身", ({"sub"+me->query("id")}));
    soldier->set_temp("id",me->query("id"));
    soldier->set("force",me->query("force")*2);
    soldier->set("max_force",me->query("max_force"));
    soldier->set("kee",me->query("max_kee"));
    soldier->set("max_kee",me->query("max_kee"));
    soldier->set("eff_kee",me->query("eff_kee")*2);
    soldier->set("combat_exp",me->query("combat_exp"));
    soldier->set("gender",me->query("gender"));
    soldier->set_temp("time",time());
    soldier->set_skill("shasword", me->query_skill("shasword",1));
    soldier->set_skill("sha-steps", me->query_skill("sha-steps",1));
    soldier->move(environment(me));
    me->do_command("team with "+"sub"+me->query("id"));
    soldier->do_command("team with "+me->query("id"));
    soldier->invocation(me);
    return 1;
}
void remove_effect(object me, int skill)
{
    int sun_moon_force=me->query_skill("sun_moon_force",1);
//	me->delete_temp("godsub"); //此刪除效果由分身npc來刪除 避免npc無限產生的bug by appo
    if(skill < 100 && skill < sun_moon_force ) //當技能等級小於100且小於心法等級時才有經驗
    function_improved("godsub",(skill*7+random(skill*8))); //根據當前技能等級來獲得相對應的經驗值
}
