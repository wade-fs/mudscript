#include <ansi.h>
#include <combat.h>
inherit NPC;
#define bell_big 400
#define bell_small 200
#define SPELLLVL 100
#define MANACOST 150
#define INVCOST 18
int special_att ();
object room2;
void create()
{
        set("title","冥殿第一殿殿主");
        set_name("陰陽怪叟",({"monster"}));
        set("max_gin",1800);
        set("gin",1800);
        set("race","野獸");
        set("age",620);
        set("str", 55);
        set("max_kee", 1500);
        set("kee", 1500);
        set("limbs", ({ "頭部", "身體", "前腳" , "後腳" , "尾巴" }) );
        set("verbs", ({ "bite"}));
        set("combat_exp",450000);
        set_temp("apply/armor",70);
        set_temp("apply/attack", 65);
        set("force_factor",10);
        set("bellicosity",1200);
        set("max_sen",2000);
        set("sen",2000);
        set("max_atman",1500);
        set("atman",1500);
        set("max_mana",1000);
        set("mana",1000);
        set("max_force",2000);
        set("force",2000);
        set("cor", 30);
        set("cps", 35);

        set("chat_chance_combat",30);
        set ("chat_msg_combat", ({(: special_att :)}));

        command("wield all");
        command("wear all");
        set_skill("hell-evil",80);
        map_skill("parry","hell-evil");
        set("unarmed",80);
        map_skill("unarmed","hell-evil");
        set_skill("dodge",60);
        set_skill("fly-steps", 60);
        map_skill("dodge","fly-steps");
        set_skill("parry",80);
setup();
    add_money("gold",10);
}
int accept_kill(object ob)
{
        int i;
        object ob1,hu_fa;
        string place;
        ob1 = this_object();

        if( !present("hu-fa", environment(ob)) )
        {
        tell_room(environment(ob),HIW + "\n突然！衝出兩位護法!!\n\n" + NOR);
        for(i=0;i<2;i++)
         {
         hu_fa = new("/open/tendo/room/tower/npc/hu_fa");
         hu_fa->move(environment(ob));
         hu_fa->kill_ob(this_player());
         }
        }
        write("護法縱身飛撲過來叫道：大膽狂徒！殿主你也敢動！！\n");
        return 1;
}



int spell ()
{
  return SPELLLVL;
}

int manacost ()
{
  return MANACOST;
}

int invcost ()
{
  return INVCOST;
}

int special_att ()
{
  object me = this_object ();
  object *enemy = query_enemy (), victim;
  int i = sizeof (enemy), damage;
  victim = enemy[random(i)];
message_vision(HIB+
"          －－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  一  式 －－" + NOR + "
                  " + HIB + "～『  " + HIY + "妖 魔 聚 鼎" + HIB + "  』～" + NOR + "
          " + HIW + "陰陽怪叟身形倏而騰飛三丈,凌空劈出一" + NOR + "
    " + HIW + "股掌勁,綿綿掌影,如江河缺堤似,暴瀉而下,掌風如激流" + NOR + "
                  " + HIW + "般地向你隔空劈來!" + NOR + "
           " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  二  式 －－" + NOR + "
                  " + HIB + "～『  " + HIR + "魔 性 狂 發" + HIB + "  』～" + NOR + "
          " + HIW + "陰陽怪叟滿頭銀髮迎風如濤,雙目吐光如炬," + NOR + "
    " + HIW + "忽然雙臂抖舞,幻化成千百條手臂,每一條手臂撲出一般渾" + NOR + "
             " + HIW + "雄的掌風,慢天的掌影向你捲劈而來!" + NOR + "
           " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  三  式 －－" + NOR + "
                  " + HIB + "～『  " + HIW + "鬼 氣 貫 腦" + HIB + "  』～" + NOR + "
          " + HIW + "陰陽怪叟雙手暴長，臉部青絲暴露，濃烈的惡" + NOR + "
    " + HIW + "臭從雙掌透出，只見陰陽怪叟雙手不停疾舞，勁氣中夾帶著" + NOR + "
  " + HIW + "令人聞之欲嘔的毒氣,使得你受到毒氣的影響，受到不輕的傷害!" + NOR + "
           " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  四  式 －－" + NOR + "
                  " + HIB + "～『  " + HIC + "魑 魅 魍 魎" + HIB + "  』～" + NOR + "
          " + HIW + "陰陽怪叟一聲龍吟般的長嘯,挫身飛騰,身形盪" + NOR + "
    " + HIW + "空迴舞,一連串動作在同一石火電光之間完成,自不同的方向," + NOR + "
  " + HIW + "不同的角度,那宛如似厲鬼魔爪般的掌影,向你詭異奇絕的飛劈而至!" + NOR + "
           " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  五  式 －－" + NOR + "
                  " + HIB + "～『  " + MAG + "鬼 魅 拜 月" + HIB + "  』～" + NOR + "
          " + HIW + "只見陰陽怪叟身形一躬，雙掌前劈，一道半月" + NOR + "
    " + HIW + "形的勁氣猛然向前湧去，雄渾的勁氣，刮得地面如飛沙走石般" + NOR + "
                       " + HIW + "地向你狂襲而去!!" + NOR + "
           " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  六  式 －－" + NOR + "
                  " + HIB + "～『  " + HIY + "掌 不 刃 血" + HIB + "  』～" + NOR + "
          " + HIW + "陰陽怪叟雙掌化成千百掌影,掌影又凝成一股驚" + NOR + "
              " + HIW + "天動魄的勁氣,朝向破風聲來處劈去!!" + NOR + "
           " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  七  式 －－" + NOR + "
                  " + HIB + "～『  " + HIC + "妖 鬼 莫 測" + HIB + "  』～" + NOR + "
          " + HIW + "陰陽怪叟屈體弓身，雙掌緊貼地面，全身籠罩在" + NOR + "
    " + HIW + "一片藍光中，地面宛如波濤般浮動，隨著蓄積的內勁，藍光不斷" + NOR + "
   " + HIW + "增加，只見陰陽怪叟突然將雙掌一合，一道駭人藍箭向你疾射而去!" + NOR + "
           " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  八  式 －－" + NOR + "
                  " + HIB + "～『  " + HIR + "風 魔 狂 轉" + HIB + "  』～" + NOR + "
          " + HIW + "陰陽怪叟以氣貫入雙爪 ,雙爪閃出一陣耀目金光," + NOR + "
    " + HIW + "氣提十二成 ,勁注全身 ,蓄勢準備使出最強最霸道的一式,霎時" + NOR + "
  " + HIW + "狂龍魔氣急速旋繞陰陽怪叟 ,無儔魔氣因此驚動天地之氣 ,互抗暴出" + NOR + "
 " + HIW + "數道紫電雷光 ,陰陽怪叟忽然現身於你前 ,對你使出了石破天驚的一擊!" + NOR + "
           " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  九  式 －－" + NOR + "
                  " + HIB + "～『  " + HIY + "鬼 影 重 重" + HIB + "  』～" + NOR + "
          " + HIW + "無窮無盡的勁力由四周湧入陰陽怪叟體內，只見陰" + NOR + "
    " + HIW + "陽怪叟雙掌不停做著細微的變化，彷彿如黑洞般，將萬物都吞食" + NOR + "
                 " + HIW + "淹滅,忽然雙掌擊向你的全身!" + NOR + "
           " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  十  式 －－" + NOR + "
                  " + HIB + "～『  " + HIW + "鬼 氣 無 濤" + HIB + "  』～" + NOR + "
          " + HIW + "陰陽怪叟狂吼一聲,上空平身挪後三寸,左手拍地,右" + NOR + "
    " + HIW + "手股動內勁,破天而出,掌勁如山,激起無濤的氣勁,夾著雷霆萬駒" + NOR + "
                       " + HIW + "之勢朝你而來!!" + NOR + "
         " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  十  一  式 －－" + NOR + "
                  " + HIB + "～『  " + HIC + "鬼 焰 凌 厲" + HIB + "  』～" + NOR + "
          " + HIW + "陰陽怪叟左足橫移,挫腰沈身,單袖一揚,瞬時狂風拂" + NOR + "
    " + HIW + "起, 塵沙飛揚,陰陽怪叟趁飛沙走石之際,運起陽剛真氣,身形一旋," + NOR + "
      " + HIW + "雙掌內攏,催起一股凌厲的氣焰,朝你的天靈蓋連續拍出數掌!" + NOR + "
         " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "第  十  二  式 －－" + NOR + "
                  " + HIB + "～『  " + HIR + "群 魔 亂 舞" + HIB + "  』～" + NOR + "
          " + HIW + "陰陽怪叟閃身反掌擊出，一道青色光芒從掌中發出，" + NOR + "
    " + HIW + "使你分不清身在何方，只見陰陽怪叟身形一展，幻化成千萬身影," + NOR + "
 " + HIW + "身影中夾帶著沉重的掌勁向你罩下,你正在遲疑之際已被無數掌影所擊中!" + NOR + "
        " + HIB + "－－ " + HIW + "冥  殿  " + HIR + "絕  " + HIY + "學  " + HIB + "之  " + HIC + "終  " + RED + "極  " + MAG + "秘  " + HIW + "技 " + HIB + "－－" + NOR + "
                  " + HIB + "～『  " + MAG + "千  魂  滅  散" + HIB + "  』～" + NOR + "
          " + HIW + "陰陽怪叟重重的掌,連疊的拳,萬鈞之力,渾雄之氣,煞" + NOR + "
    " + HIW + "時天空彷彿突然黑暗下來,妖魔彷彿都從墓地爬了起來,推山倒海," + NOR + "
 " + HIW + "大地翻滾,縱橫上下空間,為掌風與掌影所佈,有如綿綿飛際的利刃擊向你!!\n"+NOR,me);

  if (random (2) >= 1)
    {
      damage = 30+(victim->query ("max_kee") / 8);
   if (damage < 40)
        damage = 40;
      if (damage > 250)
        damage = 250;
message_vision(HIR + "$N不幸被掌風劈中 , 頓時全身血如泉湧.\n" + NOR,victim);
      victim->apply_condition ("bleeding", random (i * i));
      victim->receive_damage ("kee", damage, me);
      COMBAT_D->report_status (victim, 0);
    }
  else
    {
message_vision(HIW + "只可惜離$N差了一點, 劈到地上, 轟的一聲巨響, 地皮頓時裂了開來.\n" + NOR,victim);
    }
  start_busy (1);
  return 1;
}



