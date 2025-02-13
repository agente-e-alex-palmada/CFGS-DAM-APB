package dao;

import java.util.List;
import model.Player;
import org.hibernate.*;
import util.NewHibernateUtil;

/**
 *
 * @author Usuari
 */
public class Dao {
    
    public static Dao daoGeneric = null;
    
    private SessionFactory factory;
    private Transaction transaction;

    public Dao() {
        factory = NewHibernateUtil.getSessionFactory();
    }
    
    public static Dao getInstance(){
        if(daoGeneric==null){
            daoGeneric=new Dao();
        }
        return daoGeneric;
    }
    
    public boolean create(Object o){
        boolean go_back = false;
        Session session = factory.openSession();
        try{
            transaction = session.beginTransaction();
            session.save(o);
            transaction.commit();
            go_back=true;
            
        }
        catch (Exception e){
            transaction.rollback();
            go_back = false;
            e.printStackTrace();
        } finally{
            session.close();
        }
        return go_back;
    }
    public boolean delete(int id) {
       boolean go_back = false;
        Session session = factory.openSession();
        try{
            transaction = session.beginTransaction();
            
            Player o = (Player) session.load(Player.class, id);
       
      //first load() method example
     
            session.delete(o);
            transaction.commit();
            go_back=true;
            
        }
        catch (Exception e){
            transaction.rollback();
            go_back = false;
            e.printStackTrace();
        } finally{
            session.close();
        }
        return go_back;
    }
    public List readPlayer(){
        List result=null;
        try {
        Session session = factory.openSession();
        session.beginTransaction();
        Query q = session.createQuery("FROM player");
        result = (List) q.list();
        
        //sessio.getTransaction().commit();
    } catch (HibernateException he) {
        he.printStackTrace();
    }
        return result;
    }
}
