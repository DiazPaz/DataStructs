using std::string;
class Calificacion
{

    private:
        string nombreAlumno; 
        double calActividades;
        double calExamen; 
        double calProyecto; 

    public: 
        void setNombreAlumno(string nombre){ nombreAlumno = nombre; }
        void setActividades(double cal){ calActividades = cal; } 
        void setExamen(double ex){ calExamen = ex; } 
        void setCalProyecto(double pro){ calProyecto = pro; } 

        string getNombreAlumno(){ return nombreAlumno; }
        double getActividades(){ return calActividades; } 
        double getExamen(){ return calExamen; } 
        double getCalProyecto(){ return calProyecto; } 

};