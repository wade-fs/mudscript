// sun_jen.c
// 加入銀針解謎物件-by nike-
#include <ansi.h>
inherit NPC;

string ask_pnx();
string ask_wine();

void create()
{
        set_name("任朝陽", ({ "trainer jen", "jen" }) );
        set("title", "瀧山派第八代奧義任家傳人");
        set("nickname", "酒狂");
        set("gender", "男性" );
        set("age",30);
        set("str", 30);
        set("int", 24);
        set("inquiry",([
             "買酒"     :  (: ask_wine :),
             "火鳳羽"     :  (: ask_pnx :),
        ]));
        set("long",
                 "任朝揚是瀧山派奧義的任家傳人, 亦是任家的長子, 他所使用的『瀧山\n" +
                 "絕學』(Lungshan)是其父正晴館主親授之絕學, 由於身為長子必須以發\n" +
                 "揚瀧山派為己任, 因此自小勤於習武, 其拳術與其父不分軒冕, 但是他\n" +
                 "嗜酒如命, 卻不至沈醉, 將醉步溶入絕學中, 使其更勝一籌, 有青勝藍\n" +
                 "之勢, 同時曾獲得城中武術冠軍, 所以大家都稱他為『 酒狂 』！\n");
        set("attitude", "heroism");
        set("env/狂擊","YES");
        set("combat_exp", 500000);
        set("force",2800);
        set("max_force", 2800);
        set("force_factor", 15);
        set("inquiry", ([
                "here": "這裡是任家正晴武館, 請問有何事指教?\n",
                "name": "在下姓任, 名朝陽, 是本館的副館主。",
                "lungshan": "喔....此為本館絕學, 在下對此頗有研究,承蒙家父栽培!\n",
        ]) );
        set("super_fire",1);
        set_skill("lungshan", 90);
        set_skill("dodge"   , 50);
        set_skill("haoforce", 60);
        set_skill("force"   , 70);
        set_skill("unarmed", 70);
        set_skill("parry", 70);
        set_skill("henma-steps",60);
        set_skill("fire-kee",50);
        map_skill("force", "haoforce");
        map_skill("unarmed", "lungshan");
        map_skill("dodge", "henma-steps");
        map_skill("parry", "fire-kee");
        set("chat_chance_combat",65);
        set("chat_msg_combat",({
            (: perform_action, "force.kang_kee"   :),
        }));
        setup();
         carry_object(__DIR__"obj/fight_robe")->wear();
         carry_object("/open/wu/npc/obj/fireclaw.c")->wield();
         carry_object(__DIR__"obj/armband")->wear();
}
int accept_object(object me, object ob)
{
    string name = ob->query("name");

    if(me->query("get_wine") == 1)
{
    if(name == HIR + "<滿>" + HIC + "十錦琺瑯杯" + NOR)
{
        command("snort "+me->query("id"));
        command("say 你...你搞啥啊...現...現在才來！");
        command("drinking");
        call_out("say_pnx",3,me);
        return 1;
    }
  }
}
int say_pnx(object me)
{
    object ob;

        write(HIY + "任朝陽恍恍惚惚的說道：mmm...說到我們瀧山派的鎮派聖獸－赤羽火鳳吶！\n" + NOR,me);
        write(HIY + "任朝陽恍恍惚惚的說道：不...不是我在臭屁的...ㄜ！...牠的羽...羽毛，真是絕世美物...\n" + NOR,me);
        write(HIY + "任朝陽恍恍惚惚的說道：我看...ㄜ！看在你..你幫我買酒的份上...就給你機會去...ㄜ！去拔看看...\n" + NOR,me);
        write(HIY + "任朝陽恍恍惚惚的說道：ㄜ！藏經閣之鑰在這...這兒...嗯...但我可不...不保證你...ㄜ！你能成功\的...拿到羽毛唷...\n" + NOR,me);
        ob=new("/open/doctor/obj/key");
        ob->move(me);
        me->set("get_key",1);
        me->delete("get_wine");
        destruct(ob);
        return 1;
}
string ask_pnx()
{
    object me=this_player();

    if(me->query("ask_baby")==1)
{
        command("arc "+me->query("id"));
        command("say 啥咪...火...火鳳羽ㄚ？ㄜ！嗯...聽某啦！");
        command("say 咦？你...你是哪ㄜ！..位ㄚ？別在這妨礙我喝....喝酒，閃開！");
        command("drinking");
        command("cow");
        command("say 可惡！又沒酒了...ㄜ！喂！那個誰...幫我去買酒...快！");
        me->delete("ask_baby");
        me->set("ask_wine");
  }
}
string ask_wine()
{
    object me=this_player();

    if(me->query("ask_wine")==1)
{
        command("slap "+me->query("id"));
        command("say 豬頭啊你！當然是到...風...的...嗯....zｚZＺ");
        command("sleep");
        write(HIY + "任朝陽模模糊糊的說著夢話：酒...冰清冽酒...給我..冰清冽酒...mmm...\n" + NOR);
        me->delete("ask_wine");
        me->set("ask_flor");
  }
}
