// cloud-sword for 雲龍天宮 by nike...02/03/2002
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
inherit SKILL;

void super(object me,object target,object weapon,int damage);
void busy(object me,object target,object weapon,int damage);
void delbusy(object me,object target,object weapon,int damage);
void attack(object me,object target,object weapon,int damage);
void damage(object me,object target,object weapon,int damage);
void recover(object me, object target, object weapon, int damage);
void att1(object me, object target, object weapon, int damage);

mapping *action = ({
    ([
        "action"     : HIC + "$N祭出" + HBBLU+HIW + "ζ雲龍劍訣ζ" + NOR+HIG + "◎ 起手式 ◎" + HIY + "《 雲雨蒼茫 》" + HIC + "，$N手中$w" + HIC + "猛抖，
腳踏奇步，$w" + HIC + "登時湧起凜冽劍氣，遙指向$n，一招攻去，似攻非守，似守非攻。" + NOR,
        "damage"     : 105,
        "dodge"      : -45,
        "parry"      : -45,
        "force"      :  25,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIG + "$N使出" + HBBLU+HIW + "ζ雲龍劍訣ζ" + NOR+HIC + "◎ 奔躍式 ◎" + HIB + "《 風起雲湧 》" + HIG + "，只見$N舞起$w" + HIG + "，
時而滿場劍光，時而勁氣收斂，$N一時身隨劍走，劍勁化作長虹，直朝$n射去。\n" + NOR,
        "damage"     : 70,
        "dodge"      : -32,
        "parry"      : -32,
        "force"      : 30,
        "post_action": (: attack :),
    ]),
    ([
        "action"     : HIW + "$N使來" + HBBLU+HIW + "ζ雲龍劍訣ζ" + NOR+HIR + "◎ 急攻式 ◎" + NOR+WHT + "《 八方雲動 》" + HIW + "，$N首將己身處於地利之中，
再以$w" + HIW + "舞起八方幻影，將劍影化成無形劍陣，並將$n困於劍陣之中。\n" + NOR,
        "damage"     : 50,
        "dodge"      : -27,
        "parry"      : -27,
        "force"      : 30,
        "post_action": (: busy :),
    ]),
    ([
        "action"     : HIY + "$N狂舞$w" + HIY + "，只見滿場$w" + HIY + "劍芒氣勁，虛則實之，實則虛之，令$n眼花撩亂，
並將$n籠罩在劍影之中，此招正是" + HBBLU+HIW + "ζ雲龍劍訣ζ" + NOR+HIW + "◎ 氣吞式 ◎" + HIC + "《 雲游百山 》" + HIY + "。\n",
        "damage"     : 80,
        "dodge"      : -18,
        "parry"      : -18,
        "force"      : 20,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIC + "忽然一陣劍光閃耀，原是$N積聚劍鋒之氣勁，如山洪般一洩而出，形成一
波又一波的劍浪，直向$n湧去，正為" + HBBLU+HIW + "ζ雲龍劍訣ζ" + NOR+HIG + "◎ 驚濤式 ◎" + HIM + "《 覆雨翻雲 》" + HIC + "。\n" + NOR,
        "damage"     : 115,
        "dodge"      : -9,
        "parry"      : -9,
        "force"      : 15,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIW + "突然$N劍鋒一轉，使來" + HBBLU+HIW + "ζ雲龍劍訣ζ" + NOR+HIY + "◎ 虛藏式 ◎" + HIG + "《 雲出無心 》" + NOR + "，似以劍氣為
守，實以劍勁為攻，突然一道劍氣突然從$w" + HIW + "劍鋒急奔而出，直衝向$n。\n" + NOR,
        "damage"     : 230,
        "dodge"      : 0,
        "parry"      : 0,
        "force"      : 25,
        "post_action": (: delbusy :),
    ]),
    ([
        "action"     : HIG + "$N手中之$w" + HIG + "忽然黯淡無光，似若氣勁已虛，而$n正待搶攻，卻被$N以一招
" + HBBLU+HIW + "ζ雲龍劍訣ζ" + NOR+HIM + "◎ 奇襲式 ◎" + HIR + "《 伏雲暗蟄 》" + HIG + "搶出，正是攻其不備，占得先機。\n" + NOR,
        "damage"     : 150,
        "dodge"      : 8,
        "parry"      : 8,
        "force"      : 10,
        "post_action": (: damage :),
    ]),
    ([
        "action"     : HIY + "$N將真氣化為陰陽兩勁，並貫勁於劍鋒，順而使出" + HBBLU+HIW + "ζ雲龍劍訣ζ" + NOR+HIC + "◎ 破空式 ◎
" + HIG + "《 松柏浮雲 》" + HIY + "，只見劍氣化為松柏兩柱形自劍鋒破出，以不同方向擊向$n。\n" + NOR,
        "damage"     : 170,
        "dodge"      : 18,
        "parry"      : 18,
        "force"      : 20,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIC + "$N真氣遊走全身，使出" + HBBLU+HIW + "ζ雲龍劍訣ζ" + NOR+YEL + "◎ 護體式 ◎" + HIW + "《 天地雲龍 》" + HIC + "，將真氣化為
無形劍網在周身產生綿密的保護層，使得$n無法接近，甚而眼花撩亂之。\n" + NOR,
        "damage"     : 90,
        "dodge"      : 25,
        "parry"      : 25,
        "force"      : 20,
        "post_action": (: att1 :),
    ]),
    ([
        "action"     : HIY + "$N勁透劍尖，使出一招" + HBBLU+HIW + "ζ雲龍劍訣ζ" + NOR+HIB + "◎ 轟天式 ◎" + HIR + "《 雲破山河 》" + HIY + "，一道雄渾劍
氣直取$n咽喉，其破空之勢中夾帶孅柔飄朔之勁，威力足以震破名山巨嶽。\n" + NOR,
        "damage"     : 210,
        "dodge"      : 31,
        "parry"      : 31,
        "force"      : 20,
        "post_action": (: super :),
    ]),
    ([
        "action"     : HIG + "只見$N雙足一跨，體內真氣流轉，隨即使上" + HBBLU+HIW + "ζ雲龍劍訣ζ" + NOR+HIB + "◎ 詭譎式 ◎" + HIC + "《 重雲深鎖 》
" + HIG + "，招式中蘊含流雲萬化的神奇態勢，只見$N飛來一劍，$n一時無法招架。\n" + NOR,
     "damage"    : 230,
     "dodge"     : 38,
     "parry"     : 38,
     "force"     : 30,
        "post_action": (: super :),
    ]),
    ([
        "action"     : HIC + "
\t\t  ═══╦═══      ╦═╩╦ ╠══╯    ══╩═╰═╬═╮
\t\t╭═══╬═══╮    ╩══╩ ╰══╮     ═══     ║  ║
\t\t║╰═╮║╭═╯║    ╔══╗ ╭══╯     ═══ ══╬═╩
\t\t   ══════       ╠══╣ ╠══╯    ╭══╮╭═╯═╮
\t\t ═╦══════     ╠══╣ ╠══╯    ║    ║║      ║
\t\t   ╰════╣       ╯    ╯ ╰══╮    ╰══╯╯      ╰\n\n
" + HIW + "$N一招" + HBBLU+HIW + "ζ雲龍劍訣ζ" + NOR+HIB + "◎ 總訣式 ◎" + HIG + "《 雲龍無際 》" + HIW + "使出，真有如百人舞劍般，
急手快劍，絕妙無匹，恰似有意若無意，既趣態橫生，卻又是凶險至極。\n" + NOR,
        "damage"     : 250,
        "dodge"      : 45,
        "parry"      : 45,
        "force"      : 25,
        "post_action": (: recover :),
    ]),
});
void recover(object me, object target, object weapon, int damage)
{
    int bell, recover, sklv = me->query_skill("cloud-sword",1);
    bell = me->query("bellicosity")/10;
    if(bell > 250) bell = 250;
    recover = sklv*2-bell;
    if(sklv < bell) recover = 0;

    if(me->query("family/family_name") != "雲龍天宮") return 0;
    if( !me->query_temp("berserk") && me->query("kee") < me->query("max_kee") && random(100) > sklv*2/3) {
        message_vision(HIY + "\n$N體內的真氣爆發，自劍鋒閃出一道黃芒，並將$N完全籠罩！\n
" + HIW + "$N突然感到自己的氣力似乎已經回復了不少！\n" + NOR,me,target);
        me->receive_curing("kee",recover);
        me->receive_heal("kee",recover);
        me->add("force",sklv);
    } else return 0;
}
void busy(object me, object target, object weapon, int damage)
{
    int sklv = me->query_skill("cloud-sword",1);

    if(me->query("family/family_name") != "雲龍天宮") return 0;
    if(me->query("force") < sklv/2) return 0;
    if(me->query("force") < 200 || target->is_busy() >= 3) return 0;
        message_vision(HIM + "\n\t$N氣貫丹田，馬步站穩，順勢使上一招...\n
\t\t" + HIY + "～～～" + HIC + "《 " + HIW + "雲蹤無現" + HIC + "～" + HIR + "龍飛焰" + HIC + " 》" + HIY + "～～～\n
\t    " + HIR + "自劍身散發出一股熊熊火光，狠狠地朝$n" + HIR + "刺去！！\n\n" + NOR,me,target);
    if(!me->query_temp("berserk") && random(75) > 60-me->query_cps()) {
        message_vision(HIB + "$N的一劍刺中$n的要害罩門，一股灼熱之感，自劍端漫向$n體內，
$n登時面無血色，一臉目瞪口呆，彷彿自以驚駭無比...\n" + NOR,me,target);
        target->receive_damage("kee",sklv*2);
        target->apply_condition("burn",random(sklv)+sklv/3);
        target->start_busy(random(2)+1);
        me->add("force",-sklv);
    } else {
        message_vision(HIR + "$N的一劍刺偏，只輕掃過$n的雙肩，$n肩頭登時血如泉湧，但並無大礙...\n" + NOR,me,target);
        target->receive_damage("kee",sklv*2);
        me->add("force",-sklv/2);
    }
}
void delbusy(object me, object target, object weapon, int damage)
{
    int sklv = me->query_skill("cloud-sword",1);

    if(me->query("family/family_name") != "雲龍天宮") return 0;
    if(sklv < 40 || me->query("force") < sklv*3/2) return 0;
    if(!me->query_temp("berserk") && random(100) > 50) {
        message_vision(HIG + "\n$N被$n逼得喘不過氣，卻突然狂吼一聲，如瘋狂般開始舞起手中之劍，並吟道：\n\n
\t\t" + HIW + "『" + HIC + "孤亭突兀插飛流" + HIW + "，" + HIC + "氣壓元龍百尺樓" + HIW + "』\n
\t\t\t" + HIW + "『" + HIY + "萬里風濤按瀛海" + HIW + "，" + HIY + "千年豪傑壯山丘" + HIW + "』\n
\t\t" + HIW + "『" + HIG + "疏星澹月魚龍夜" + HIW + "，" + HIG + "老木清霜鴻雁秋" + HIW + "』\n
\t\t\t" + HIW + "『" + HIR + "倚劍長歌一杯酒" + HIW + "，" + HIR + "浮雲西北是神州" + HIW + "』\n\n
        " + NOR,me,target);
        message_vision(HIY + "  須臾...$N終於擺\脫了$n的綿密攻勢，並且以強勢快劍反將$n逼至絕境...\n" + NOR,me,target);
        target->receive_damage("kee",sklv*2);
        me->add("force",-sklv*3/2);
    } return 0;
}
void damage(object me, object target, object weapon, int damage)
{
    int bell, sklv = me->query_skill("cloud-sword",1);

    if(me->query("family/family_name") != "雲龍天宮") return 0;
    if(sklv < 90 || me->query("force") < sklv*2/3) return 0;
        message_vision(HIR + "\n
    $N手捏劍訣，暗自運行真氣入體，有如九珠一般，行遍周身大穴，\n
\t又隨即舞起手中之劍，似已幻化無數劍圈，接著縱身躍\n
    起丈餘，一個旋身，由半空中自向$n疾攻而至，口中並緩緩吟道：\n
\t  " + HIW + "--== " + HBRED+HIY + "雲" + NOR+HIW + " == " + HBRED+HIC + "起" + NOR+HIW + " == " + HBRED+HIC + "山" + NOR+HIW + " == " + HBRED+HIC + "河" + NOR+HIW + " == " + HBRED+HIC + "動" + NOR+HIW + " == " + HBRED+HIC + "九" + NOR+HIW + " == " + HBRED+HIC + "天 " + NOR+HIW + " ==--\n
\t      " + HIW + "--== " + HBRED+HIY + "龍" + NOR+HIW + " == " + HBRED+HIC + "游" + NOR+HIW + " == " + HBRED+HIC + "乾" + NOR+HIW + " == " + HBRED+HIC + "坤" + NOR+HIW + " == " + HBRED+HIC + "躍" + NOR+HIW + " == " + HBRED+HIC + "古" + NOR+HIW + " == " + HBRED+HIC + "淵 " + NOR+HIW + " ==--\n
\t\t  " + HIW + "--== " + HBRED+HIY + "劍" + NOR+HIW + " == " + HBRED+HIC + "傲" + NOR+HIW + " == " + HBRED+HIC + "孤" + NOR+HIW + " == " + HBRED+HIC + "獨" + NOR+HIW + " == " + HBRED+HIC + "孰" + NOR+HIW + " == " + HBRED+HIC + "為" + NOR+HIW + " == " + HBRED+HIC + "敵 " + NOR+HIW + " ==--\n
\t\t      " + HIW + "--== " + HBRED+HIY + "訣" + NOR+HIW + " == " + HBRED+HIC + "霸" + NOR+HIW + " == " + HBRED+HIC + "江" + NOR+HIW + " == " + HBRED+HIC + "湖" + NOR+HIW + " == " + HBRED+HIC + "離" + NOR+HIW + " == " + HBRED+HIC + "中" + NOR+HIW + " == " + HBRED+HIC + "原 " + NOR+HIW + " ==--\n
\t    " + HIY + "此招快意卓絕，妙極無言，須臾之內已出招了二十多劍，劍劍攻向$n" + HIY + "要害，\n
\t直逼得其毫無退守之餘地，只有挺身擋格，卻因此而被打亂陣腳，頭頸腹背皆以見紅。\n\n" + NOR,me,target);
    if( !me->query_temp("berserk") && random(sklv) > 45) {
        message_vision(HIR + "$N最後使上一劍中衝，直取$n之命門大穴，$n一個閃神而中招，倒地兀自流血不已...\n" + NOR,me,target);
        target->receive_wound("kee",sklv*5+random(sklv));
        target->receive_damage("kee",sklv*2+random(sklv));
        target->start_busy(1);
        me->add("force",-sklv*2/3);
    } else {
        message_vision(HIR + "$N最後使上一劍中衝，直取$n之命門大穴，$n雖舉臂擋駕，卻傷及手臂，流血不止...\n" + NOR,me,target);
        target->receive_damage("kee",sklv);
        me->add("force",-sklv/3);
    }
}
void attack(object me, object target, object weapon, int damage)
{
    int bell, sklv = me->query_skill("cloud-sword",1)*2;
    bell = me->query("bellicosity")/10;
    if(sklv < 120) sklv = 120;
    if(bell > 100) bell = 100; 
    if(bell < 45) bell = 45;

    if(me->query("family/family_name") != "雲龍天宮") return 0;
    if(me->query("force") < sklv) return 0;
        message_vision(HIC + "\n
\t$N忽而起手奔躍，轉而奇襲急攻，又似虛藏護體，實為氣吞總訣，\n
    瞬息萬變，有如龍騰鳳翔一般的舞起手中之劍，並順勢使上一招......\n
\t      " + HIY + "《--》" + HIW + "～" + HIC + "雲" + HIW + "～" + HIC + "龍" + HIW + "～" + HIC + "劍" + HIW + "～" + HIC + "訣" + HIW + "～" + HIY + "《--》" + HIR + "『奧意之式』" + NOR + "\n
" + HIY + "\t    【" + HIW + "～" + HIC + "遊" + HIW + "～" + HIC + "雲" + HIW + "～" + HIC + "無" + HIW + "～" + HIC + "常" + HIW + "～" + HIC + "相" + HIR + "˙" + HIC + "天" + HIW + "～" + HIC + "龍" + HIW + "～" + HIC + "舞" + HIW + "～" + HIC + "空" + HIW + "～" + HIC + "翔" + HIW + "～" + HIY + "】\n
    " + HIC + "一時劍光熾熾，劍芒閃耀，劍氣急竄，劍勁突奔，人劍合一，向$n狂攻而去！\n\n" + NOR,me,target);
    if(!me->query_temp("berserk") && random(sklv) > bell) {
        message_vision(HIR + "$n被劍光所震攝，忽然一個閃神，已經遭$N給痛擊了要害！！！\n" + NOR,me,target);
        target->receive_damage("gin",sklv+random(sklv/2));
        target->receive_damage("kee",sklv*2+random(sklv));
        target->receive_damage("sen",sklv+random(sklv/2));
        target->receive_wound("gin",sklv/2+random(sklv));
        target->receive_wound("kee",sklv+random(sklv*2));
        target->receive_wound("sen",sklv/2+random(sklv));
        me->add("force",-sklv);
    } else {
        message_vision(HIG + "$n腳踩步法，一個迴身，竟翩然的閃過這威力不弱的一擊...\n" + NOR,me,target);
        me->add("force",sklv/3);
        target->start_busy(1);
    }
}
void super(object me, object target, object weapon, int damage)
{
    int sklv,bell = me->query("bellicosity")/10;
    sklv = me->query_skill("cloud-sword",1);
    if(bell < 0) bell = 0;
    if(bell > 60) bell = 60;

    if(me->query("family/family_name") != "雲龍天宮") return 0;
    if(sklv < 120) return 0;
    if(!me->query("quests/free_shasword")) return 0;
    if(me->query("force") < 1200) return 0;
    if(me->query_temp("berserk")) return 0;
        message_vision(HIY + "\n$N眼綻金光，舞劍如輪，大喝一聲：「納命來！！！」，一招使上...\n
\t\t" + HBRED+HIW + "-= " + HIY + "雲龍霸劍意" + HIW + "－" + HIC + "十二式齊出 " + HIW + "=-" + NOR+HIY + "\n\n" + NOR,me,target);
    if(random(100) > 30) {
    sklv = sklv - bell;
        message_vision(HIR + "\n$N狂暴劍意，勁貫劍鋒，使出" + HIY + "《起手式》" + HIW + "◤" + NOR+GRN + "雲雨蒼茫" + HIW + "◢" + HIR + "，一招虎虎生風，去勢洶洶的攻向$n的招子。\n" + NOR,me,target);
        target->receive_damage("kee",sklv/2);
        COMBAT_D->report_status(target);
        message_vision(HIR + "\n$N狂暴劍意，勁貫劍鋒，使出" + HIY + "《奔躍式》" + HIW + "◤" + NOR+MAG + "風起雲湧" + HIW + "◢" + HIR + "，一招虎虎生風，去勢洶洶攻向$n的頸項。\n" + NOR,me,target);
        target->receive_damage("kee",sklv/2);
        COMBAT_D->report_status(target);
        message_vision(HIR + "\n$N狂暴劍意，勁貫劍鋒，使出" + HIY + "《急攻式》" + HIW + "◤" + HIB + "八方雲動" + HIW + "◢" + HIR + "，一招虎虎生風，去勢洶洶攻向$n的雙臂。\n" + NOR,me,target);
        target->receive_damage("kee",sklv/2);
        COMBAT_D->report_status(target);
        message_vision(HIR + "\n$N狂暴劍意，勁貫劍鋒，使出" + HIY + "《氣吞式》" + HIW + "◤" + NOR+CYN + "雲遊百山" + HIW + "◢" + HIR + "，一招虎虎生風，去勢洶洶攻向$n的手腕。\n" + NOR,me,target);
        target->receive_damage("kee",sklv*2/3);
        COMBAT_D->report_status(target);
        message_vision(HIR + "\n$N狂暴劍意，勁貫劍鋒，使出" + HIY + "《驚濤式》" + HIW + "◤" + HIM + "覆雨翻雲" + HIW + "◢" + HIR + "，一招虎虎生風，去勢洶洶攻向$n的胸口。\n" + NOR,me,target);
        target->receive_damage("kee",sklv*2/3);
        COMBAT_D->report_status(target);
        message_vision(HIR + "\n$N狂暴劍意，勁貫劍鋒，使出" + HIY + "《虛藏式》" + HIW + "◤" + NOR+WHT + "雲出無心" + HIW + "◢" + HIR + "，一招虎虎生風，去勢洶洶攻向$n的肚皮。\n" + NOR,me,target);
        target->receive_damage("kee",sklv+random(sklv));
        COMBAT_D->report_status(target);
        message_vision(HIR + "\n$N狂暴劍意，勁貫劍鋒，使出" + HIY + "《奇襲式》" + HIW + "◤" + NOR+YEL + "伏雲暗蟄" + HIW + "◢" + HIR + "，一招虎虎生風，去勢洶洶攻向$n的腰際。\n" + NOR,me,target);
        target->receive_damage("kee",sklv*2);
        COMBAT_D->report_status(target);
        message_vision(HIR + "\n$N狂暴劍意，勁貫劍鋒，使出" + HIY + "《破空式》" + HIW + "◤" + HIG + "松柏浮雲" + HIW + "◢" + HIR + "，一招虎虎生風，去勢洶洶攻向$n的鼠奚。\n" + NOR,me,target);
        target->receive_damage("kee",sklv*2+random(sklv/2));
        COMBAT_D->report_status(target);
        message_vision(HIR + "\n$N狂暴劍意，勁貫劍鋒，使出" + HIY + "《護體式》" + HIW + "◤" + HIC + "天地雲龍" + HIW + "◢" + HIR + "，一招虎虎生風，去勢洶洶攻向$n的大腿。\n" + NOR,me,target);
        target->receive_damage("kee",sklv*2+random(sklv));
        COMBAT_D->report_status(target);
        message_vision(HIR + "\n$N狂暴劍意，勁貫劍鋒，使出" + HIY + "《詭譎式》" + HIW + "◤" + HIY + "重雲深鎖" + HIW + "◢" + HIR + "，一招虎虎生風，去勢洶洶攻向$n的膝頭\n。" + NOR,me,target);
        target->receive_damage("kee",sklv*3);
        COMBAT_D->report_status(target);
        message_vision(HIR + "\n$N狂暴劍意，勁貫劍鋒，使出" + HIY + "《轟天式》" + HIW + "◤" + HIR + "雲破山河" + HIW + "◢" + HIR + "，一招虎虎生風，去勢洶洶攻向$n的小腿。\n" + NOR,me,target);
        target->receive_damage("kee",sklv*3+random(sklv/2));
        COMBAT_D->report_status(target);
        message_vision(HIR + "\n$N狂暴劍意，勁貫劍鋒，使出" + HIY + "《總訣式》" + HIW + "◤" + HIW + "雲龍無際" + HIW + "◢" + HIR + "，一招虎虎生風，去勢洶洶攻向$n的足踝。\n" + NOR,me,target);
        target->receive_damage("kee",sklv*4+random(sklv));
        COMBAT_D->report_status(target);
        COMBAT_D->report_status(target);
        COMBAT_D->report_status(target);
        target->start_busy(2);
        me->add("force",-1200);
        me->start_busy(1);
    } else {
        message_vision(HIB + "沒料到居然被$n" + HIB + "突如其來的一招給攻破劍勢，而$N只傷到$n" + HIB + "的一點皮毛，
並無給予重擊，反而$N自身頓時失去重心，自空中重摔於地...\n" + NOR,me,target);
        me->add("force",-200);
        target->receive_damage("kee",sklv*2);
    }
}
// 從 gold-blade 直接偷過來改的喔...by nike
void att1(object me, object victim, object weapon, int damage)
{
    int lose, i, bell = me->query("bellicosity")/100;
    if(bell < 1) bell = 1;
    if(bell > 15) bell = 15;
    lose = (int)me->query_skill("cloud-sword",1)/20-random(bell)+1;

    if(me->query_temp("berserk")) return 0;
    if(me->query("force") < 120) return 0;
    if(lose < 1) lose = 1;
    if(lose > 20) lose = 20;
    for(i = 0;i < lose; i++) {
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        me->set_temp("berserk",1);
        me->add("force",-120);
        if(me->query("force") < 0) me->set("force",0);
    }
        me->delete_temp("berserk");
}
int valid_learn()
{
    object me = this_player();
    object ob = me->query_temp("weapon");

    if(me->query("max_force") < 60)
        return notify_fail("你的內功\根基不足，無法學習《雲龍劍訣》。\n");
    if(!ob) return notify_fail("你手中無劍，如何學習《雲龍劍訣》？\n");
        return 1;
}
int valid_enable(string usage) { return (usage=="sword"); }
mapping query_action(object me, object weapon)
{
    object target = offensive_target(me);
    int sk = me->query_skill("cloud-sword",1);
    int da = sk*(random(2)+5);
    da = random(da)+da/2;
    weapon = me->query_temp("weapon");

    if(weapon) {
    if(me->query("force") >= 450 && me->query("bellicosity") <= 50) {
    if(me->query("family/family_name") == "雲龍天宮"
    && weapon->query("id") == "cloud-dragon sword"
    && sk >= 80 && random(100) > 85 && target) {
message_vision(HIC + "$N手中的"+weapon->name()+"在體內浮雲勁氣的導引之下，竟幻化為一尾翔空雲龍，朝$n騰飛而去！\n" + NOR,me,target);
message_vision(@LONG

[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m/[1m|[1m [1m [1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m^[1m^[1m^[1m-[1m-[1m_[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m_[1m-[1m^[1m^[1m^[1m^[1m^[1m^[1m-[1m_[1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m.[1m_[1m-[1m-[1m-[1m;[1m/[1m^[1m [1m^[1m [1m [1m [1m`[1m.[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1mv[1m [1m [1m [1m [1m [1m/[1m^[1m^[1m [1mv[1m [1m [1m^[1m^[1m [1m [1m^[1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m([1m([1m [1m)[1m;[1m/[1m^[1m [1m [1m [1m [1m [1m>[1m [1m>[1m [1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m\[1m [1m [1m [1m [1m [1m([1m:[1m)[1m [1m [1m [1m/[1m^[1m [1m^[1m([1m:[1m)[1m [1m [1m^[1m [1m [1m>[1m>[1m`[1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m/[1m [1m^[1m^[1m [1m [1m>[1m [1m [1m [1m [1m>[1m [1m>[1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m\[1m [1m [1m [1m [1m([1m:[1m:[1m)[1m [1m/[1m [1m [1m [1m([1m:[1m:[1m)[1m [1m;[1m>[1m [1m/[1m [1m>[1m>[1m`[1m/[1m|[1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m/[1m^[1m^[1m^[1m [1m [1m [1m,[1m-[1m.[1m [1m [1m [1m>[1m [1m>[1m>[1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m\[1m [1m [1m [1m([1m:[1m:[1m)[1m,[1m^[1m^[1m^[1m.[1m([1m:[1m:[1m)[1m/[1m`[1m/[1m [1m [1m [1m>[1m>[1m>[1m`[1m/[1m|[1m [1m [1m [1m [1m [1m [1m,[1m/[1m^[1m^[1m [1m [1m [1m^[1m;[1m [1m [1m [1m`[1m.[1m [1m [1m [1m>[1m [1m>[1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m [1m<[1m_[1m)[1m:[1m:[1m:[1m:[1m:[1m([1m_[1m>[1m/[1m [1m/[1m`[1m.[1m_[1m-[1m-[1m.[1m [1m [1m`[1m/[1m|[1m [1m [1m [1m [1m [1m;[1m/[1m^[1m [1m [1m^[1m [1m [1m;[1m-[1m_[1m.[1m [1m [1m`[1m.[1m.[1m [1m>[1m [1m [1m>[1m`[1m/[1m|[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m\[1m|[1m:[1m:[1m:[1m|[1m:[1m:[1m:[1m|[1m/[1m [1m/[1m [1m [1m [1m([1m [1m)[1m)[1m [1m [1m>[1m`[1m/[1m|[1m [1m [1m [1m,[1m/[1m^[1m [1m^[1m [1m [1m [1m;[1m([1m [1m)[1m)[1m [1m [1m [1m [1m [1m;[1m [1m [1m>[1m>[1m [1m`[1m/[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m [1m\[1m_[1m:[1m|[1m:[1m_[1m/[1m [1m [1m/[1m [1m [1m [1m [1m`[1m.[1m [1m [1m [1m [1m [1m>[1m`[1m/[1m|[1m [1m,[1m/[1m^[1m^[1m [1m [1m [1m^[1m [1m;[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m;[1m>[1m [1m [1m>[1m [1m/[1m;[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m\[0;1;5;31m@[0;1;36m,[1m [1m.[0;1;5;31m@[0;1;36m/[1m [1m/[1m [1m [1m [1m [1m [1m [1m`[1m.[1m [1m [1m>[1m [1m>[1m [1m`[1m-[1m-[1m [1m^[1m^[1m [1m^[1m [1m^[1m [1m;[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m;[1m [1m>[1m [1m>[1m [1m/[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m [1m\[1m=[1m:[1m=[1m/[1m [1m/[1m [1m [1m [1m [1m [1m [1m [1m_[1m`[1m.[1m [1m [1m [1m [1m>[1m [1m [1m>[1m [1m>[1m [1m [1m>[1m [1m [1m;[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m`[1m [1m>[1m [1m [1m/[1m;[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m\[1m\[1m=[1m:[1m=[1m/[1m/[1m [1m [1m [1m [1m [1m [1m [1m([1m([1m,[1m`[1m.[1m>[1m [1m>[1m [1m [1m [1m [1m>[1m [1m>[1m [1m_[1m/[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m,[1m'[1m [1m>[1m [1m>[1m [1m/[1m,[0m
[0;1;36m [1m [1m [1m [1m [1m [1m [1m [1;33m [1m_[1;36m [1m [1m [1m [1m<[1mo[1m_[1mo[1m>[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m^[1m`[1m-[1m_[1m_[1m [1m>[1m [1m_[1m_[1m_[1m-[1m^[1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m_[1m,[1m'[1m [1m>[1m>[1m [1m [1m/[1m;[0m
[0;1m [1m [1;33m^[1m^[1m-[1m_[1m_[1m [1;31m/[1m^[1m^[1m\[1;33m [1m_[1m-[1;37m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;36m^[1m^[1m^[1m^[1m^[1m_[1m-[1m^[1m=[1m-[1m-[1m^[1m^[1m.[1m.[1m.[1m_[1m'[1m [1m>[1m>[1m [1m [1m/[0m
[0;1m [1m [1m [1m [1;33m^[1m^[1m-[1;31m|[1m [1m [1m'[1m;[1m|[1;33m_[1m_[1m-[1m^[1m^[1m^[1m-[1m_[1m_[1m_[1m [1;37m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;36m_[1m^[1m_[1m^[1m-[1m-[1m.[1m.[1m.[1m.[1m_[1m_[1m.[1m.[1m.[1m/[0m
[0;1m [1m [1m [1;33m_[1m_[1m_[1m-[1m_[1;31m\[1m_[1m_[1m/[1;33m-[1m-[1m^[1m^[1m^[1m [1m [1;37m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1m [1;36m^[1m^[1m^[0m

LONG+NOR,me,target);
        message_vision(HIW + "雲龍騰飛於空，忽口吐赤紅火珠，隨即朝$n俯衝直下，狂勁似雷，迅疾如電！\n" + NOR,me,target);
        message_vision(HIY + "\n雲龍旋舞長嘯一聲，聲若旱天洪雷，震得$n七昏八素，腦子裡嗡嗡亂叫！\n" + NOR,me,target);
        COMBAT_D->report_status(target);
        message_vision(HIR + "雲龍揮舞著銳爪展開瘋狂攻擊，$n一時閃躲不及，而導致全身皮綻肉裂！\n" + NOR,me,target);
        COMBAT_D->report_status(target);
        message_vision(RED + "雲龍口中的火珠突然朝$n馳飛而去，由於來得突然，$n慘遭火珠灼身，痛苦不已！\n" + NOR,me,target);
        COMBAT_D->report_status(target);
        target->start_busy(1);
        target->receive_damage("kee",da);
        target->receive_damage("gin",da/5);
        target->receive_damage("sen",da/5);
        me->add("force",-(random(150)+300));
        message_vision(HIB + "\n雲龍在完成使命之後，又幻化為劍形，落回$N的手中。\n" + NOR,me,target);
        }
    }
  }
    sk = sk/10;
    if(sk < 2) return action[random(3)];
    else if(sk < 4) return action[random(6)];
    else if(sk < 8) return action[random(9)];
    else return action[random(sizeof(action))];
}
string perform_action_file(string action)
{
        return CLASS_D("swordsman")+"/cloud-sword/"+action;
}


