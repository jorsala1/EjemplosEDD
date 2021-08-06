#ifndef STACKNODE_H
#define STACKNODE_H


class stacknode
{
    public:
        //constructores
        stacknode();
        stacknode(int valor_, stacknode *prev_);
        int valor;
        stacknode *prev;


        virtual ~stacknode();

    protected:

    private:

};

#endif // STACKNODE_H
