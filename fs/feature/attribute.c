#include <dbase.h>
int query_str(int mode)
{
  if(mode) return query("str");
  return query_temp("apply/str")+query("str");
}
int query_int(int mode)
{
  if(mode) return query("int");

  return query_temp("apply/int")+query("int");
}
int query_con(int mode)
{
  if(mode) return query("con");

  return query_temp("apply/con")+query("con");
}
int query_cor(int mode)
{
  if(mode) return query("cor");

  return query_temp("apply/cor")+query("cor");
}
int query_spi(int mode)
{
  if(mode) return query("spi");

  return query_temp("apply/spi")+query("spi");
}
int query_kar(int mode)
{
  if(mode) return query("kar");

  return query_temp("apply/kar")+query("kar");
}
int query_cps(int mode)
{
  if(mode) return query("cps");

  return query_temp("apply/cps")+query("cps");
}
int query_per(int mode)
{
  if(mode) return query("per");

  return query_temp("apply/per")+query("per");
}

