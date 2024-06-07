#ifndef LINEA_H
#define LINEA_H

class Linea {
public:
    Linea(int x_ini, int y_ini, int x_fin, int y_fin);

    int getXInicial() const;
    int getYInicial() const;
    int getXFinal() const;
    int getYFinal() const;

    void setXInicial(int x_ini);
    void setYInicial(int y_ini);
    void setXFinal(int x_fin);
    void setYFinal(int y_fin);

private:
    int x_inicial;
    int y_inicial;
    int x_final;
    int y_final;
};

#endif // LINEA_H
