#ifndef FCTUTILESADMINISTRATEUR_H
#define FCTUTILESADMINISTRATEUR_H

void setCommande(int i,const char *T);
const char* getCommande(int i)const;
void setDisponible(int i,const char *T);
const char* getDisponible(int i)const;
void setPersonnel(int i,const char *T);
const char* getPersonnel(int i)const;

void setSelectionCommande(const char *T);
const char* getSelectionCommande()const;
void setSelectionPersonnel(const char *T);
const char* getSelectionPersonnel()const;
void setNomCommande(const char *T);
const char* getNomCommande()const;

const char* getCommandeN(int i) const;
int getCommandeT(int i) const;
void MessageInformation(const char*, const char *);
#endif
