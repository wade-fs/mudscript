//by frequency
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("薛農",({"information vendor","vendor"}));
        set("long",@LONG

        狂想空間中央情報局(Central Information of FS)的高級特務，
        他的腦裡裝著最新的門派情報及大陸秘辛，只要你給他錢的話...

LONG);
        set("gender","男性");
        set("clan_kill",1);
        set("class","prayer");
        set("family/family_name","極北冰原");
        set("nickname",HIW + "我看見" + NOR);
        set("title",HIC + "CIFS" + HIM + "番號" + HIG + "49" + HIY + "情報員" + NOR);
        set("combat_exp",19000000);
        set("attitude","friendly");
        set("score",1000000);
        set("age",32);
        set("max_kee",200000);
        set("str", 50);
        set("cor", 50);
        set("cps", 45);
        set("int", 42);
        set("kar", 99);
        set("spi", 67);
        set("force",999999);
        set("max_force",99999);
        set("force_factor", 90);
        set("max_gin",90000);
        set("max_sen",90000);
        set_skill("superforce", 260);
        set_skill("dodge", 120);
        set_skill("hero", 120);
        set_skill("force",150);
        set_skill("move", 120);
        set_skill("literate",120);
        set_skill("parry", 120);
        set_skill("unarmed",120);
        set_skill("canon",150);
        set_skill("literate",120);
        set_skill("shift-steps",150);
        set_skill("universe",140);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","hero");
        set_temp("magic-manor/goldmagic",1);
        set_temp("magic-manor/woodmagic",1);
        set_temp("magic-manor/watermagic",1);
        set_temp("magic-manor/firemagic",1);
        set_temp("magic-manor/soilmagic",1);
        set_temp("apply/armor",150);
        set_temp("apply/attack",150);
        set_temp("apply/damage",150);
        set_temp("apply/defense",150);

        setup();

        carry_object("/autoload/open-area/super_hands")->wear();
        carry_object("/autoload/north-polar/light-ring")->wear();
        carry_object("/autoload/open-area/plate")->wear();
        carry_object("/autoload/open-area/light_cloak")->wear();
        carry_object("/autoload/open-area/armband")->wear();
        carry_object("/autoload/open-area/turtle-shield")->wear();
        carry_object("/autoload/open-area/bird_legging")->wear();
        carry_object("/autoload/open-area/ghost-heart")->wear();
        carry_object("/autoload/open-area/divine_belt")->wear();
        carry_object("/open/dancer/obj/linrboots")->wear();
        carry_object("/autoload/open-area/five-turn");
        carry_object("/autoload/open-area/snake_amulet");
        carry_object("/open/capital/obj/icer")->wield();
}

void init()
{
   command("wear hands");
   command("wear all");
   ::init();
}

void greeting()
{
        command("suck soul");
        command("turn five");
        command("pray amulet");
        return;
}

int accept_object(object who, object ob)
{
        int value=ob->value();
        string str;
        
        if(who->query_temp("info_fail"))
           value = value + who->query_temp("info_fail");
        if(value < 10000)
          {       
             command("say 這麼一點小錢也想買情報喔。");
             who->set_temp("info_fail",value);
             return 1;       
          }
         who->delete_temp("info_fail");
         switch(random(17))
                  {
                  	case 0:
                        str = "疾~~~~~~~~ \n";
                        break;
                        case 1:
                        str = "據說每天早晚11:00左右都會有神秘劍客出沒，打敗他們得到的戰功\，可以在京城換取防具喔！\n";
                        break;
                        case 2:
                        str = "聽說射日派最近開發出新的超遠程箭技，飛將軍似乎知道一些端倪。\n";
                        break;
                        case 3:
                        str = "惡人最近越來越凶了，簡直是逢人便揍，說不定是杜殺又創出什麼絕招了。\n";
                        break;
                        case 4:
                        str = "聽說聖火教皇正在尋找失落的渾天水晶，似乎和聖火教的失傳古武學有很大淵源\n";
                        break;
                        case 5:
                        str = "最近去過一趟聚靈山莊，看見莊主把玩一個漂亮的五彩轉輪。\n";
                        break;
                        case 6:
                        str = "如果集齊整套一十三件死靈骨魔的戰甲，好像會得到很非常強大的力量喔！\n";
                        break;
                        case 7:
                        str = "中央驛站東南方的風雲鎮，有個神奇的老人出沒。\n";
                        break;
                        case 8:
                        str = "朝廷對神出鬼沒的南蠻三霸下了追緝令，打敗他們可得到豐厚的戰功\喔！\n";
                        break;
                        case 9:
                        str = "死靈骨魔派了蛇郎君埋伏在中央驛站東方某處，不知道有何打算。\n";
                        break;
                        case 10:
                        str = "神秘劍客雖強，遇上魔界金典和英雄真經的傳人還是只有仆街的份吧，在京城的天嬰竟妄想超越他們...\n";
                        break;
                        case 11:
                        str = "聽說天上有時會掉下寶藏。\n";
                        break;
                        case 12:
                        str = "許\多人喜歡把裝備放在自己的房間裡，以測安全。\n";
                        break;
                        case 13:
                        str = "威路古‧扎基爾夫對海皇的封印力量似乎越來越薄弱了，北方的海神殿最近充滿了不安的氣息。\n";
                        break;
                        case 14:
                        str = "有時戰鬥結束後會拿到天靈地界的奇異物品，聽說風雲鎮老人可以幫你處理。\n";
                        break;
                        case 15:
                        str = "好累喔，讓我休息一下\n";
                        break;
                        case 16:
                        str = "請愛用do tin tin。\n";
                        break;
                  }
                command("say "+str);

        destruct(ob);
        return 1;
}
