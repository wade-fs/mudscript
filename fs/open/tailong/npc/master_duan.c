// 段家 掌門人
#include "/open/open.h"
int exert_sunforce();
inherit NPC;
inherit F_MASTER;
string do_thief();
string do_scar();
string do_chao();
string do_firecracker();
void create()
{
        set_name("段雲",({"lord duan","lord","duan"}));
        set("long","段雲便是當今皇上冊封的平南王, 同時也是段家武學的第十代傳人, "+
"雖然貴為王爺, 自有一肚子的墨水, 但其一身祖傳的武學卻也沒忘, 可說是文武雙全, "+
"也因為如此, 段雲自是非常重視文學素養, 若想拜入段家武學的門下, 則非是一位書生不可。\n");
        set("gender","男性");
        set("class","scholar");
        set("nickname","平南王");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",50);
        set("max_kee",3000);
        set("kee", 3000);
        set("str", 44);
        set("cor", 24);
        set("cps", 45);
        set("per", 30);
        set("int", 42);
        set("inquiry", ([
        "thief"         : (: do_thief :),
        "scar"          : (: do_scar :),
        "sad_story"     : "若你不知道其中緣由,就不要再問了。",
        "chao"          : (: do_chao :),
        "firecracker"   : (: do_firecracker :),
        "一陽心法秘笈"  : "這一陽心法的秘笈聽說已由柳毅風尋獲, 只是不知他何時回來。",
        ]));
        set("force",3000);
        set("max_force",3000);
        set("force_factor", 10);
        set_skill("cure", 60);
        set_skill("dodge", 70);
        set_skill("force",80);
        set_skill("move", 70);
        set_skill("parry", 70);
        set_skill("stabber",120);
        set_skill("unarmed",20);
        set_skill("literate",120);
        set_skill("sunforce",80);
        set_skill("linpo-steps",100);
        set_skill("six-fingers",100);
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("move","linpo-steps");
        map_skill("parry","six-fingers");
        map_skill("stabber","six-fingers");
        map_skill("unarmed","six-fingers");
        set("functions/handwriting/level",50);
        set("marks/sun-finger",1);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action("stabber.handwriting") :),
                (: this_object(),"exert_sunforce" :),
        }));
        setup();
        carry_object(PING_OBJ"neck0")->wear();
        carry_object(PING_OBJ"cloud_fan")->wield();
        add_money("gold",10);
        create_family("段家",10,"掌門人");
}

void init()
{
        add_action("do_answer","answer");
        set_heart_beat(1);
}
void heart_beat()
{
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
                if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
        }
        }
        :: heart_beat();
}       

string do_thief()
{
        object me=this_player();
        if( me->query_temp("thief") < 4 )
          return("京城的大盜..嗯..與我段家有關嗎﹖");
        else
        {
          command("sigh");
          return("唉..沒想到..他..唉..");  
        }
}
string do_scar()
{
        object me=this_player();
        if( me->query_temp("thief") >= 3 )
        {
        if( me->query_temp("thief") == 3 )      me->set_temp("thief",4);
          return("大盜的右耳後有一小傷痕, 且使的是段家的\武\功\嗎﹖難道..難道是他..\n\n"+
          "段雲陷入深深的沈思之中, 似乎在回想著什麼。\n\n"+
          "段雲抱歉的說道: 我不想再提起這段傷心往事(sad_story)了。來人啊,送客..");
        }
        else
          return("啥..誰的傷痕﹖");
}
string do_chao()
{
        object me=this_player();
        object key=new(PING_OBJ"key0");
        if( me->query_temp("thief") >= 5 )
        {
          if( me->query_temp("thief") == 5 )    me->set_temp("thief",6);
          command("say 唉..你也知道了這件事了啊..是柳毅風跟你說的吧..其實過了"+
          "這麼多年, 我也該面對現實了。趙琴風變成京城大盜, 也算是段家管"+
          "教不周所致, 現在要引出趙琴風, 只有一個辦法, 就是用我們段家獨"+
          "門的聯絡煙火, 他看到了煙火必定會出現。");
          message_vision("$N交給$n一把鐵鑰匙。\n",this_object(),me);
          key->move(me);
          return("這是我們段家儲藏室的鑰匙, 你可以在那找到聯絡用的炮仗");
        }
}
string do_firecracker()
{
        object me=this_player();
        if( me->query_temp("thief") >= 6 )
        {
          if( me->query_temp("thief") == 6 )    me->set_temp("thief",7);
          return("啊..抱歉忘了說明炮仗的使用方法, 這炮仗需要在高地燃放才行, "
          +"且在燃放前要先︿＆％︿＊＆＠＃....明白了吧。");
        }
        else
          return("疑..你怎會知道這這炮仗的事, 給我老實道來!!");
}

int exert_sunforce()
{
        object ob=this_object();
        if( ob->query("kee") < ob->query("max_kee")/2 )
        if( !present("sunforce finger",ob) )
        {
          command("say 好..老夫就陪你玩玩。");
          command("exert sun-finger");
          command("wield finger");
        }
        return 1;
}

int do_answer(string str)
{
        object me=this_player();
        string *answer = ({
        "虞兮虞兮奈若何",
        "去日苦多",
        "對影成三人",
        "悠然見南山",
        "春風不度玉門關",
        "西出陽關無故人",
        "共此燈燭光",
        "此恨綿綿無絕期",
        "蠟炬成灰淚\始乾",
        "千古風流人物",
         "一步江湖無盡期",
         "濁酒一杯笑紅塵",
         "竊竊暗笑世人癡",
         "神機妙算讚白蓮"
        });
        if(me->query_temp("answer") < 0);
        else
        {
          if(str == answer[me->query_temp("answer")])
          {
            command("pat "+me->query("id"));
            write("很好﹐" + RANK_D->query_respect(me) + "的文學底子不錯, 多加努力, "+
            "他日必能為段家發揚光大, 在江湖上揚名立姓。\n");
            command("recruit " + me->query("id") );
            me->set("startroom",environment(me));
            write("嗯..你的內功\不夠純正, 讓為師的助你一臂之力吧。\n");
            message_vision("段雲緩緩的伸出右手, 往$N頭頂的百會穴一按, 絲絲的蒸氣從$N的頭上冒了出來....。\n",me);
            me->improve_skill("sunforce",2);
            command("smile "+me->query("id"));
            write("好了, 為師已將一小部份的一陽心法傳與你, 望你能再接再勵, 終於大成。\n");
            CHANNEL_D->do_channel(this_object(), "chat",
            sprintf("%s成為段家的一員了, 希望大家能本著江湖精神照顧他。",me->name(1)));
          }
          else
          {
            command("sigh "+me->query("id"));
            write(RANK_D->query_respect(me)+"你的文學素養太淺了, 也許\應該多去品嚐書籍, "+
            "下次有把握了再來找我吧...\n");
          }
          me->delete_temp("answer");
        }
        return 1;
}               

void attempt_apprentice(object me)
{
        int which;
        string *question = ({
        "項羽『核下歌』\n「力拔山兮氣蓋\世! 時不利兮騅不逝! 騅不逝兮可奈何! .......」",
        "曹操『短歌行』\n「對酒當歌, 人生幾何? 譬如朝露, ....」",
        "李白『月下獨酌』\n「花間一壺酒, 獨酌無相親; 舉杯邀明月, .....」",
        "陶淵明『飲酒』\n「結盧在人間, 而無車馬喧。問君何能爾, 心遠地自偏。採菊東離下, .....。」",
        "王之渙『涼州詞』\n「黃河遠上白雲間, 一片孤城萬仞山。羌笛何須怨楊柳, .......。」",
        "王維『渭城曲』\n「渭城朝雨浥清塵, 客舍青青柳色新。勸君更進一杯酒, .......。",
        "杜甫『贈衛八處士』\n「人生不相見, 動如參與商。今夕復何夕, .....」",
        "白居易『長恨歌』\n「在天願做比翼鳥, 在地願為連理枝。天長地久有時盡, .......!",
        "李商隱『無題』\n「相見時難別亦難, 東風無力百花殘。春蠶到死絲方盡; .......",
        "大江東去, 浪淘盡, ......」",
            "錦鯉欲躍龍門池, 北風一動離水時, 戰火燒斷逍遙夢.......",
            "世事如棋局局新, 豪傑似浪翻不盡, 古往今來多少事.......",
            "還真為逐青雲志, 一生真偽有誰知, 堂堂滿言仁義情.......",
            "靈車赫赫天下驚, 妖聲邪氣瀰滿天, 金葉一動清香現......."
        });
        which=random(sizeof(question));
        if(me->query_temp("have_apprentice"))
          write("怎麼這麼快又見面了? 下次再來吧。\n");
        else
        {
        write(" + "+RANK_D->query_respect(me)+"想拜入我的門下嗎? 我門的內功\首重內心修養, "+
        "若學識沒有一定的基礎, 對自身反而有害。老夫這就來試一試你, 若真心想學的話就回答(answer)我的問題吧\n");
        write("段雲緩緩的吟唱道: fl;"+question[which]+"fc;\n");
        write("段雲和藹的說道: 你能說說接下來的句子嗎?\n");
        me->set_temp("have_apprentice",1);
        me->set_temp("answer",which);
        }
}
int accept_object(object me, object obj)
{
        if( obj->query("name") == "一陽心法秘笈" )
        {
          command("pat "+getuid(me));
          command("say 太好了, 是柳毅風託你的嗎﹖謝了。");
          if( me->query("family/family_name") == "段家" && !me->query("marks/sun-finger") )
          {
            command("say 既然你護送秘笈有功\, 我便將此秘笈上記載的絕招傳授與你吧。");
            write(this_object()->query("name")+"看著秘笈隨手演練一遍。\n\n"+
            "你覺得心中疑慮豁然貫通, 全身內力迅速流轉一周天。\n\n"+
            "你的內力值達到上限了。\n\n"+
            "你學會了一陽心法中的絕招「化氣為筆」。\n\n");
            if( me->query("force") < me->query("max_force") )
              me->set("force",me->query("max_force"));
            me->set("marks/sun-finger",1);
          }
          destruct(obj);
        }
        else
          command("? "+getuid(me));
        return 1;
}
              
void unconcious()
{
        object winner = query_temp("last_damage_from");
        tell_object(users(),"\n\t『天下風雲出我輩  一入江湖歲月摧\n\t\t皇圖霸業談笑中  不勝人生一場醉』\n"+
        "\n\t想我段雲縱橫江湖, 今日敗於"+winner->query("name")+"之手\n\t可謂  時也～  運也～  命也～\n");
        :: unconcious();
}
void die()
{
        object winner = query_temp("last_damage_from");
        tell_object(users(),"\n\n南方天空畫過一道流星。\n\n\t「天機星落」\n\n");
        :: die();
}                      
