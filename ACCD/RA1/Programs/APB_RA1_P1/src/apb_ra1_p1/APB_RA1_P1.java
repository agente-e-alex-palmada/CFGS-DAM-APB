JugadorType jugador1 = new JugadorType();
	
		jugador1.setNom ("Xavi");
                jugador1.setNivell(14);

		CartaType carta1= new CartaType();
                carta1.setNivellcart(14);
                carta1.setNomcart("Caballero");
                carta1.setRaresa("comuna");
                
		jugador1.getCarta().add(carta1);

		
                
              
                clash.getJugador().add(jugador1);
                
		try {
			File file = new File("./clashMarshaller.xml");
			JAXBContext jaxbContext = JAXBContext.newInstance(ClashType.class);
			Marshaller jaxbMarshaller = jaxbContext.createMarshaller();
			// output pretty printed
			jaxbMarshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
			jaxbMarshaller.setProperty(Marshaller.JAXB_ENCODING, "UTF-8");
			jaxbMarshaller.marshal(clash, file);
			jaxbMarshaller.marshal(clash, System.out);
		} catch (JAXBException e) {
			e.printStackTrace();
		}