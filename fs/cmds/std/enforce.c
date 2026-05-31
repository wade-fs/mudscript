// enforce.c
// 10/28重新修正 by chan
// 給予瀧山派高一點的enforce的值
// 最多為enforce 35但是至少haoforce要過300 force lv要過200才有可能
inherit F_CLEAN_UP;

int main(object me, string arg)
{
 int pts,fval,hval;
 if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) )
         return notify_fail("指令格式﹕enforce <使出幾成內力傷敵>|none\n");
 if( !me->query_skill_mapped("force") )
         return notify_fail("你必須先 enable 一種內功\。\n");
 if( arg=="none" )
         me->delete("force_factor");
 else {
if(me->query("class")!="fighter"&&me->query("class")!="bonze"&&me->query("class")!="doctor"&&!wizardp(me))
           if(pts<0||pts>10)
           return notify_fail("你只能用 none 表示不運內力﹐或 0 到 10 的數字表示用幾成內力。\n");
   if(me->query("class")=="fighter"||me->query("class")=="bonze"||me->query("class")=="doctor")
    {
      if(pts<0||pts>(10+this_player()->query_skill("force")/25))
           return notify_fail("你只能用 none 表示不用內力﹐或 0 到 "+sprintf("%d",me->query_skill("force")/25+10)+" 的數字表示用幾成內力。\n");
     }
   me->set("force_factor", pts);
        }
        write("Ok.\n");
        return 1;
}

int help (object me)
{
        write(@HELP
指令格式 : enforce <使出幾成內力傷敵>|none
指令說明 : 
           這個指令讓你指定每次擊中敵人時﹐要發出幾成內力傷敵。
           enforce none 則表示你不使用內力。 
其他參考 :
           enable，enchant
HELP
        );
        return 1;
}
