void run(
		final ImagePlus imp,
		final boolean largest,
		final boolean middle,
		final boolean smallest,
		final boolean absolute,
		final String scale
	) {

		try {
			double scaleval;
			try { scaleval = Double.parseDouble(scale); }
			catch (Exception e) { throw new IllegalArgumentException("Invalid smoothing scale value"); }

			final Image img = Image.wrap(imp);
			final Aspects aspects = img.aspects();
			if (!FJ_Options.isotropic) img.aspects(new Aspects());
			final Hessian hess = new Hessian();
			hess.messenger.log(FJ_Options.log);
			hess.messenger.status(FJ_Options.pgs);
			hess.progressor.display(FJ_Options.pgs);

			final Vector<Image> eigenimages = hess.run(new FloatImage(img),scaleval,absolute);

			final int nrimgs = eigenimages.size();
			for (int i=0; i<nrimgs; ++i)
				eigenimages.get(i).aspects(aspects);
			if (nrimgs == 2) {
				if (largest) FJ.show(eigenimages.get(0),imp);
				if (smallest) FJ.show(eigenimages.get(1),imp);
			} else if (nrimgs == 3) {
				if (largest) FJ.show(eigenimages.get(0),imp);
				if (middle) FJ.show(eigenimages.get(1),imp);
				if (smallest) FJ.show(eigenimages.get(2),imp);
			}

			FJ.close(imp);

		} catch (OutOfMemoryError e) {
			FJ.error("Not enough memory for this operation");

		} catch (IllegalArgumentException e) {
			FJ.error(e.getMessage());

		} catch (IllegalStateException e) {
			FJ.error(e.getMessage());

		} catch (Throwable e) {
			FJ.error("An unidentified error occurred while running the plugin");

		}