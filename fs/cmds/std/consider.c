// consider.c 
// 以實戰經驗 氣的最大值 防禦力 攻擊力 str con 及 殺氣
// 以公式判斷敵我 並加入 實力差別之級數 
// by Anmy  98/5/28 初版

#include <ansi.h>
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}
int main(object ob, string str)
{

int range,range1,range2,range3,range4;
int ex1,ex2,ke1,ke2,wc1,wc2,be1,be2;
int at1,at2,st1,st2,co1,co2;
ex2=this_player()->query("combat_exp");
ke2=(int)this_player()->query("max_kee");
wc2=(int)this_player()->query_temp("apply/armor");
at2=(int)this_player()->query_temp("apply/damage");
st2=(int)this_player()->query_str();
co2=(int)this_player()->query_con();
be2=(int)this_player()->query("bellicosity");
range1=(ex2/4+ke2+wc2*2+be2+at2*2+st2+co2);
    if(!str) {
	notify_fail("使用方法 : <consider [對象]>\n");
	return 0;
    }
    ob = present(str,environment(this_player()));
    if(!ob) {
	notify_fail(str+" 不在這裡\n");
	return 0;
    }

    if(ob==this_player()) {
        notify_fail("自己和自己比較的結果是一樣的\n");
//write("你凝氣聚精來感應自己全身的狀態, 你憑本身的修為\n估計目前的綜合能力約 "+HIC+range1+NOR+" 上下\n");
        return 0;
    }
ex1=ob->query("combat_exp");
ke1=(int)ob->query("max_kee");
wc1=(int)ob->query_temp("apply/armor");
at1=(int)ob->query_temp("apply/damage");
st1=(int)ob->query_str();
co1=(int)ob->query_con();
be1=(int)ob->query("bellicosity");
range3=((ex1+ex2)/200);
range2= (ex1/4+ke1+wc1*2+be1+at1*2+st1+co1);
if(wizardp(this_player())) printf("range3=%d\n",range3);
if(!range3) range3=1;
if(!range2) range2=1;
range= ((range2/range3)-(range1/range3));
        if(range < - 30) {
         write("你要殺死"+ob->name()+"就如要踩死螞蟻般容易\n");
write("你以本身修為判斷"+ob->name()+"的江湖歷練大約是"HIR"超級肉腳"NOR"的級數\n");
       return 1;
    }
          if(range < -25) {
      write("哇哈哈哈～, "+ob->name()+"看起來根本不是你的對手!\n");
write("你以本身修為判斷"+ob->name()+"的江湖歷練大約是"HIR"普通肉腳"NOR"的級數\n");
	return 1;
     }
     if (range < -20) {
	write("你感覺"+ob->name()+"不過是個大肉腳, 根本不屑一顧\n");
write("你以本身修為判斷"+ob->name()+"的江湖歷練大約是"HIC"小卒仔"NOR"的級數\n");
         return 1;
     }
       if (range < -15) {
write("雖然從各方面看來你都比"+ob->name()+"略勝一籌, 但是也不能輕敵。\n");
write("你以本身修為判斷"+ob->name()+"江湖歷練大約是"HIC"普通角色"NOR"的級數\n");
      return 1;
     }
    else if(range < -5) {
    write("你感覺"+ob->name()+"跟你勢鈞力敵, 看來將有一場龍爭虎鬥\n");
write("你以本身修為判斷"+ob->name()+"的江湖歷練大約是"HIY"不分上下"NOR"的級數\n");
       return 1;
    }
      else if(range < 10) {
write("你感覺"+ob->name()+"比你強一點, 你必需要有充份的準備才有勝算。\n");
write("你以本身修為判斷"+ob->name()+"的江湖歷練大約是"HIY"普通硬角"NOR"的級數\n");
          return 1;
       }
       else if(range < 20) {
         write("小心點﹐"+ob->name()+"比你略勝一籌, 你的勝算不大\n");
write("你以本身修為判斷"+ob->name()+"的江湖歷練大約是"HIY"一般高手"NOR"的級數\n");
       return 1;
       }
        else if(range < 25) {
        write("小心點﹐"+ob->name()+"可是很硬的喔, 得花一番功\夫\n");
write("你以本身修為判斷"+ob->name()+"的江湖歷練大約是"HIM"武林高手"NOR"的級數\n");
       return 1;
    }
          else if(range < 30) {
          write("算了吧, 要打倒 "+ob->name()+" 得再回去苦練十年\n");
          write(HIC"你開始感覺到一股強大的氣息向你逼進\n"NOR);
write("你以本身修為判斷"+ob->name()+"的江湖歷練大約是"HIM"深不可測"NOR"的級數\n");
        return 1;
       }
       else if(range <35) {
          write("憑你的實力想打倒"+ob->name()+", 簡直是難如登天\n");
write(HIY"你感覺到一股十分強大的氣息向你迫進\n"NOR);
write("你以本身修為判斷"+ob->name()+"的江湖歷練大約是"HIW"空前絕後"NOR"的級數\n");
         return 1;
      }
    else {
write("別夢想了 , 直接去自殺也許\對你還比較快喔, "+ob->name()+"的實力深不可測!\n");
write(HIY"你感覺到十分驚人的力量和殺氣從"+ob->name()+"身上散發出來\n"NOR);
write("你以本身修為判斷"+ob->name()+"的江湖歷練大約是"HIW"天神般無所倫比"NOR+"的級數\n");
       return 1;  
    }
}

void help() {
    write(@HELP
    指令用法 : <consider [對象]>
    比較你和對方的強度
HELP
);
}
